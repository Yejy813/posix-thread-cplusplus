#ifndef __POSIX_PORT_H__
#define __POSIX_PORT_H__
// we also can use #param once

#include "posix_define.h"
#include <functional>
#include <pthread.h>

__POSIX_THREAD_BEGIN

/**
 * 线程同步四项原则：
 *  1. 首要原则是尽量最低限度地共享对象，减少需要同步的场合。
 *     一个对象能不暴露给别的线程就不要暴露； 如果要暴露， 优先考虑immutable对象(内部数据的不可变导致其更加安全，
 *     可以用作多线程的共享对象而不必考虑同步问题)；实在不行才暴露可修改的对象，并用同步措施来充分保护它。
 *  2．其次是使用高级的并发编程构件， 如TaskQueue、 ProducerConsumer Queue、 CountDownLatch等等。
 *  3．最后不得已必须使用底层同步原语（primitives）时，只用非递归的互斥器和条件变量，慎用读写锁，不要用信号量。
 *  4．除了使用atomic整数之外， 不自己编写lock-free代码， 也不要用“内核级”同步原语。不凭空猜测
 *     “哪种做法性能会更好”， 比如spin lock vs.mutex。
 *
 ***/

/**
 * mutex 封装原则
 *  1. 用RAII手法封装mutex的创建、销毁、加锁、解锁这四个操作，保证锁的生效期间等于一个作用域（scope），
 *     不会因异常而忘记解锁。
 * 
 *  2. 只用非递归的mutex（即不可重入的mutex）.
 * 
 *  3. 不手工调用lock()和unlock()函数，一切交给栈上的Guard对象的构造和析构函数负责。Guard对象的生命期
 *     正好等于临界区（分析对象在什么时候析构是C++程序员的基本功）。这样我们保证始终在同一个函数同一个
 *     scope里对某个mutex加锁和解锁。避免在foo()里加锁，然后跑到bar()里解锁；也避免在不同的语句分支中
 *     分别加锁、解锁。这种做法被称为Scoped Locking。
 * 
 *  4. 在每次构造Guard对象的时候，思考一路上（调用栈上）已经持有的锁，防止因加锁顺序不同而导致死锁（deadlock）。 
 *     由于Guard对象是栈上对象，看函数调用栈就能分析用锁的情况，非常便利。
 *   
 * 次要原则：
 *  1. 不使用跨进程的mutex， 进程间通信只用TCP sockets（跨网络）。
 *  2. 加锁、解锁在同一个线程，线程a不能去unlock线程b已经锁住的mutex（RAII自动保证） 
 *  3. 别忘了解锁（RAII自动保证）。
 *  4. 不重复解锁（RAII自动保证）。
 *  5. 必要的时候可以考虑用PTHREAD_MUTEX_ERRORCHECK来排错。
 */

class MutexLock
{
public:
  MutexLock();
  ~MutexLock();

  MutexLock(const MutexLock &mutex) = delete;
  MutexLock &operator=(const MutexLock &mutex) = delete;

  void lock();
  void unlock();
  bool IsLockedByThisThread() const;
  pthread_mutex_t *getPthreadMutex();

private:
  friend class Condition;

private:
  pthread_mutex_t mutex_;
  pid_t holder_;
};

/**
 * Use as a stack variable, eg.
 * int Foo::size() const
 * {
 *   MutexLockGuard lock(mutex_);
 *   return data_.size();
 * }
 * 
 **/

template <typename T>
class MutexLockGuard
{
public:
  MutexLockGuard(const MutexLockGuard &mutex) = delete;
  MutexLockGuard &operator=(const MutexLockGuard &mutex) = delete;

  explicit MutexLockGuard(T &mutex)
      : mutex_(mutex)
  {
    mutex_.lock();
  }

  ~MutexLockGuard()
  {
    mutex_.unlock();
  }

private:
  T &mutex_;
};

/**
 * condition variable 封装原则
 *  互斥器（mutex）是加锁原语，用来排他性地访问共享数据，它不是等待原语。在使用mutex的时候，我们一般
 *  都会期望加锁不要阻塞，总是能立刻拿到锁。然后尽快访问数据，用完之后尽快解锁，这样才能不影响并发性和性能。
 *  如果需要等待某个条件成立， 我们应该使用条件变量（condition variable）条件变量顾名思义是一个或多个线程
 *  等待某个布尔表达式为真， 即等待别的线程“唤醒”它。 条件变量的学名叫管程（monitor）
 * 
 *  条件变量只有一种正确使用的方式， 几乎不可能用错。 对于wait端：
 * 
 *  1. 必须与mutex一起使用， 该布尔表达式的读写需受此mutex保护.
 *  2. 在mutex已上锁的时候才能调用wait().
 *  3. 把判断布尔条件和wait()放到while循环中.
 * 
 *  对于临界区，需要使用while循环来等待条件变量， 而不能用if语句，原因是spurious wakeup（虚假唤醒）
 *  对于signal/broadcast端：
 *  1. 不一定要在mutex已上锁的情况下调用signal（理论上）。
 *  2. 在signal之前一般要修改布尔表达式。
 *  3. 修改布尔表达式通常要用mutex保护（至少用作full memory barrier）。
 *  4. 注意区分signal与broadcast：“broadcast通常用于表明状态变化，signal通常用于表示资源可用。
 * 
 *  条件变量是非常底层的同步原语，很少直接使用，一般都是用它来实现高层的同步措施，如：
 *  BlockingQueue<T>或CountDownLatch。
 * 
 *  倒计时（CountDownLatch）是一种常用且易用的同步手段。 它主要有两种用途：
 *  1. 主线程发起多个子线程，等这些子线程各自都完成一定的任务之后，主线程才继续执行。通常用于主线程
 *     等待多个子线程完成初始化。
 *  2. 主线程发起多个子线程，子线程都等待主线程，主线程完成其他一些任务之后通知所有子线程开始执行。通常用
 *     于多个子线程等待主线程发出“起跑”命令
 * 
 */

class Condition
{
public:
  Condition(const Condition &cond) = delete;
  Condition &operator=(const Condition &cond) = delete;

  explicit Condition(MutexLock &mutex);
  ~Condition();

  void Wait();

  void Signal();

  void SignalAll();

private:
  MutexLock &mutex_;
  pthread_cond_t cond_;
};

__POSIX_THREAD_END
#endif // !__POSIX_PORT_H__