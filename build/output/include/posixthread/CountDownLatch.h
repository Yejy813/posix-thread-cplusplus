#ifndef __COUNTDOWNLATCH_H__
#define __COUNTDOWNLATCH_H__
#include "posix_port.h"

__POSIX_THREAD_BEGIN

/**
 * 
 *  CountDownLatch是一个同步工具类，用来协调多个线程之间的同步，能够使一个线程在等待另外
 *  一些线程完成各自工作之后，再继续执行。使用一个计数器进行实现。计数器初始值为线程的数量。
 *  当每一个线程完成自己任务后，计数器的值就会减一。当计数器的值为0时，表示所有的线程都已经
 *  完成了任务，然后在CountDownLatch上等待的线程就可以恢复执行任务。
 * 
 *  典型用法1 ：某一线程在开始运行前等待n个线程执行完毕。主线程需要等待多个组件加载完毕，之后再继续执行。
 *  典型用法2 ：实现多个线程开始执行任务的最大并行性。多个线程在某一时刻同时开始执行。
 *             做法是初始化一个共享的CountDownLatch(1)，将其计数器初始化为1，多个线程在开始执行任务前
 *             首先 coundownlatch.Wait()，当主线程调用 CountDown() 时，计数器变为0，多个线程同时被唤醒。
 **/

class CountDownLatch
{
public:
  CountDownLatch(const CountDownLatch &latch) = delete;
  CountDownLatch &operator=(const CountDownLatch &latch) = delete;

  explicit CountDownLatch(int count);

  void Wait();

  void CountDown();

  int GetCount() const;

private:
  mutable MutexLock mutex_;
  Condition condition_;
  int count_;
};

__POSIX_THREAD_END
#endif // __COUNTDOWNLATCH_H__