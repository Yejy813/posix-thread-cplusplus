#include "posix_port.h"
#include <cstring>

__POSIX_THREAD_BEGIN

static void PthreadCall(const char *label, int result)
{
  if (result != 0)
  {
    fprintf(stderr, "File:%s, Line:%d, pthread %s: %s\n", __FILE__, __LINE__, label, strerror(result));
    abort();
  }
}

// mutex
MutexLock::MutexLock()
    : holder_(0)
{
  PthreadCall("init pthread", pthread_mutex_init(&mutex_, NULL));
}

MutexLock::~MutexLock()
{
  PthreadCall("destroy mutex", pthread_mutex_destroy(&mutex_));
}

void MutexLock::lock()
{
  PthreadCall("lock", pthread_mutex_lock(&mutex_));
  holder_ = pthread_self();
}

void MutexLock::unlock()
{
  holder_ = 0;
  PthreadCall("unlock", pthread_mutex_unlock(&mutex_));
}

pthread_mutex_t *MutexLock::getPthreadMutex()
{
  return &mutex_;
}

bool MutexLock::IsLockedByThisThread() const
{
  return holder_ == pthread_self();
}

// Condition variable
Condition::Condition(MutexLock &mutex)
    : mutex_(mutex)
{
  PthreadCall("init cv", pthread_cond_init(&cond_, NULL));
}

Condition::~Condition()
{
  PthreadCall("destroy cv", pthread_cond_destroy(&cond_));
}

void Condition::Wait()
{
  PthreadCall("wait", pthread_cond_wait(&cond_, mutex_.getPthreadMutex()));
}

void Condition::Signal()
{
  PthreadCall("signal", pthread_cond_signal(&cond_));
}

void Condition::SignalAll()
{
  PthreadCall("broadcast", pthread_cond_broadcast(&cond_));
}

__POSIX_THREAD_END