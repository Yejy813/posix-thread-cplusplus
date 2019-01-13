#include <gtest/gtest.h>
#include <posix_thread.h>

class Foo
{
public:
  explicit Foo(double x)
      : x_(x)
  {
  }

  void memberFunc(int i, const std::string strText)
  {
    printf("tid=%d, Foo::x_=%f, i=%d\n", PosixThread::CurrentThread::tid(), x_, i);
  }

private:
  double x_;
};

void threadFunc()
{
  std::cout << "tid= " << PosixThread::CurrentThread::tid() << std::endl;
}

void threadFunc2(int x)
{
  printf("tid=%d, x=%d\n", PosixThread::CurrentThread::tid(), x);
}

PosixThread::MutexLock g_mutex;
void TextMutex()
{
  PosixThread::MutexLockGuard<PosixThread::MutexLock> lock(g_mutex);
  std::cout << "pid= " << ::getpid() << "   tid= " << PosixThread::CurrentThread::tid() << std::endl;
  std::cout << "wait for 3 sec" << std::endl;
  sleep(3);
}

TEST(PosixThreadTest, CreateThread)
{
  std::cout << "pid= " << ::getpid() << "   tid= " << PosixThread::CurrentThread::tid() << std::endl;

  // test 1
  PosixThread::Thread t1(threadFunc);
  t1.start();
  ASSERT_TRUE(t1.started());
  std::cout << "t1.tid: " << t1.tid() << std::endl;
  std::cout << "thread name: " << t1.name().c_str() << std::endl;
  t1.join();

  // test 2
  PosixThread::Thread t2(std::bind(threadFunc2, 77),
                         "thread for free function with argument");
  t2.start();
  ASSERT_TRUE(t2.started());
  std::cout << "t2.tid: " << t2.tid() << std::endl;
  std::cout << "thread name: " << t2.name().c_str() << std::endl;
  t2.join();

  // test 3
  using namespace std::placeholders; // 使用 bind 的占位符, feel like test std::bind
  Foo test(36.6);
  auto memFunction = std::bind(&Foo::memberFunc, &test, 88, "hello world!");

  PosixThread::Thread t3(memFunction, "ye jia yun");
  t3.start();
  ASSERT_TRUE(t3.started());
  ASSERT_STREQ(t3.name().c_str(), "ye jia yun");
  std::cout << "t3.tid: " << t3.tid() << std::endl;
  std::cout << "thread name: " << t3.name().c_str() << std::endl;
  t3.join();

  std::cout << "CreateThread test end !\n"
            << std::endl;
}

TEST(MutexTest, Lock)
{
  // 测试 TextMutex 接口的执行顺序
  int kMaxThreads = 8;
  std::vector<PosixThread::Thread *> vec_Thread;

  for (int i = 0; i < kMaxThreads; i++)
  {
    char buff[200];
    sprintf(buff, "ThreadMutex%d\n", i);
    std::string str = buff;
    vec_Thread.push_back(new PosixThread::Thread(TextMutex, str));
    vec_Thread.back()->start();
  }

  for (int i = 0; i < kMaxThreads; ++i)
  {
    vec_Thread[i]->join();
  }

  std::cout << "MutexTest end !\n"
            << std::endl;

  for (int i = 0; i < kMaxThreads; ++i)
  {
    delete vec_Thread[i];
    vec_Thread[i] = nullptr;
  }
}

TEST(AtomicTest, AtomicInt64)
{
  std::cout << "pid= " << ::getpid() << "  tid= " << PosixThread::CurrentThread::tid() << std::endl;

  PosixThread::AtomicInt64 a0;
  ASSERT_EQ(a0.get(), 0);
  ASSERT_EQ(a0.getAndAdd(1), 0);
  ASSERT_EQ(a0.get(), 1);
  ASSERT_EQ(a0.addAndGet(2), 3);
  ASSERT_EQ(a0.get(), 3);
  ASSERT_EQ(a0.incrementAndGet(), 4);
  ASSERT_EQ(a0.get(), 4);
  a0.increment();
  ASSERT_EQ(a0.get(), 5);
  ASSERT_EQ(a0.addAndGet(-3), 2);
  ASSERT_EQ(a0.getAndSet(100), 2);
  ASSERT_EQ(a0.get(), 100);
}
