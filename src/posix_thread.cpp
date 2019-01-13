#include "posix_thread.h"
#include <time.h>
#include <sys/prctl.h>
#include <unistd.h>
#include <sys/syscall.h> /* For SYS_xxx definitions */
#include <assert.h>


__POSIX_THREAD_BEGIN

// __thread 变量每一个线程有一份独立实体，各个线程的值互不干扰
// 用于存储当前线程的数据
namespace CurrentThread
{
static const int kMicroSecondsPerSecond = 1000 * 1000;

__thread int t_cachedTid = 0;
__thread char t_tidString[32];
__thread int t_tidStringLength = 6;
__thread const char *t_threadName = "unknown";
const bool sameType = std::is_same<int, pid_t>::value;
static_assert(sameType, "pid_t is not int type!");
} // namespace CurrentThread

// Boost里常常用boost::detail来放那些"不应该暴露给客户，但又不得不放到头文件里"的函数或class。
namespace detail
{

pid_t gettid()
{
  return static_cast<pid_t>(::syscall(SYS_gettid));
}

// 线程数据，线程创建后的数据传递
struct ThreadData
{
  using ThreadFunc = PosixThread::Thread::ThreadFunc;
  ThreadFunc func_;
  std::string name_;
  pid_t *tid_;
  CountDownLatch *latch_;

  ThreadData(const ThreadFunc &func,
             const std::string &name,
             pid_t *tid,
             CountDownLatch *latch)
      : func_(func),
        name_(name),
        tid_(tid),
        latch_(latch)
  {
  }

  void runInThread()
  {
    *tid_ = PosixThread::CurrentThread::tid();
    tid_ = NULL;
    latch_->CountDown();
    latch_ = NULL;

    PosixThread::CurrentThread::t_threadName = name_.empty() ? "PosixThread" : name_.c_str();
    ::prctl(PR_SET_NAME, PosixThread::CurrentThread::t_threadName);

    try
    {
      func_();
      PosixThread::CurrentThread::t_threadName = "finished";
    }
    catch (const std::exception &ex)
    {
      PosixThread::CurrentThread::t_threadName = "crashed";
      fprintf(stderr, "exception caught in Thread %s\n", name_.c_str());
      fprintf(stderr, "reason: %s\n", ex.what());
      abort();
    }
    catch (...)
    {
      PosixThread::CurrentThread::t_threadName = "crashed";
      fprintf(stderr, "unknown exception caught in Thread %s\n", name_.c_str());
      throw; // rethrow
    }
  }
};

void *startThread(void *obj)
{
  ThreadData *data = static_cast<ThreadData *>(obj);
  data->runInThread();
  delete data;
  return NULL;
}

} // namespace detail
__POSIX_THREAD_END



using namespace PosixThread;

void CurrentThread::cacheTid()
{
  if (t_cachedTid == 0)
  {
    t_cachedTid = detail::gettid();
    t_tidStringLength = snprintf(t_tidString, sizeof t_tidString, "%5d ", t_cachedTid);
  }
}

bool CurrentThread::isMainThread()
{
  return tid() == ::getpid();
}

void CurrentThread::sleepUsec(int64_t usec)
{
  struct timespec ts = {0, 0};
  ts.tv_sec = static_cast<time_t>(usec / kMicroSecondsPerSecond);
  ts.tv_nsec = static_cast<long>(usec % kMicroSecondsPerSecond * 1000);
  ::nanosleep(&ts, NULL);
}

AtomicInt32 Thread::numCreated_;

Thread::Thread(const ThreadFunc &function, const std::string &name)
    : started_(false),
      joined_(false),
      pthreadId_(0),
      tid_(0),
      func_(function),
      name_(name),
      latch_(1)

{
  setDefaultName();
}

Thread::~Thread()
{
  if (started_ && !joined_)
  {
    pthread_detach(pthreadId_);
  }
}

void Thread::start()
{
  assert(!started_);
  started_ = true;
  detail::ThreadData *data = new detail::ThreadData(func_, name_, &tid_, &latch_);
  if (pthread_create(&pthreadId_, NULL, &detail::startThread, data))
  {
    started_ = false;
    delete data; // or no delete?
    printf("Failed in pthread_create");
  }
  else
  {
    latch_.Wait();
    assert(tid_ > 0);
  }
}

int Thread::join()
{
  assert(started_);
  assert(!joined_);
  joined_ = true;
  return pthread_join(pthreadId_, NULL);
}

void Thread::setDefaultName()
{
  int num = numCreated_.incrementAndGet();
  if (name_.empty())
  {
    char buf[32];
    snprintf(buf, sizeof buf, "Thread%d", num);
    name_ = buf;
  }
}