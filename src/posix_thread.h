#ifndef __POSIX_THREAD_H__
#define __POSIX_THREAD_H__
#include "CountDownLatch.h"
#include "Atomic.h"

__POSIX_THREAD_BEGIN

// http://blog.chinaunix.net/uid-28711483-id-4995776.html  自旋锁
// https://github.com/guidoreina/threads    // spin lock vs mutex vs auto

namespace CurrentThread
{
// internal
extern __thread int t_cachedTid;
extern __thread char t_tidString[32];
extern __thread int t_tidStringLength;
extern __thread const char *t_threadName;

void cacheTid();

inline int tid()
{
  if (unlikely(t_cachedTid == 0))
  {
    cacheTid();
  }
  return t_cachedTid;
}

inline const char *tidString() // for logging
{
  return t_tidString;
}

inline int tidStringLength() // for logging
{
  return t_tidStringLength;
}

inline const char *name()
{
  return t_threadName;
}

bool isMainThread();

void sleepUsec(int64_t usec);
} // namespace CurrentThread

class Thread
{
public:
  using ThreadFunc = std::function<void()>;

  Thread(const Thread &thread) = delete;
  Thread &operator=(const Thread &thread) = delete;

  explicit Thread(const ThreadFunc &function, const std::string &name = std::string());
  ~Thread();

  void start();
  int join();

  bool started() const { return started_; }
  pid_t tid() const { return tid_; } 
  const std::string &name() const { return name_; }

private:
  void setDefaultName(); // 设置线程名

private:
  bool started_;         // 是否开始执行
  bool joined_;          // 主线程是否等待子线程执行完
  pthread_t pthreadId_;  // 线程 ID
  pid_t tid_;            // 线程的 tid, 系统内是唯一id，不同进程中线程各不相同； 
                         // pthread_self 进程内唯一，不同进程可能相同
                         
  std::string name_;     // 线程名字
  ThreadFunc func_;      // 线程执行函数
  CountDownLatch latch_; // 创建线程先于主线程执行

  static AtomicInt32 numCreated_; // 原子操作
};

__POSIX_THREAD_END
#endif // !__POSIX_THREAD_H__