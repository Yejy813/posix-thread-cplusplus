#include "CountDownLatch.h"

__POSIX_THREAD_BEGIN

CountDownLatch::CountDownLatch(int count)
    : mutex_(),
      condition_(mutex_),
      count_(count)
{
}

void CountDownLatch::Wait()
{
  MutexLockGuard<MutexLock> lock(mutex_);

  while (count_ > 0)
  {
    condition_.Wait();
  }
}

void CountDownLatch::CountDown()
{
  MutexLockGuard<MutexLock> lock(mutex_);
  --count_;

  if (count_ == 0)
  {
    condition_.SignalAll();
  }
}

int CountDownLatch::GetCount() const
{
  MutexLockGuard<MutexLock> lock(mutex_);
  return count_;
}

__POSIX_THREAD_END