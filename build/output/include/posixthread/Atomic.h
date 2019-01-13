#ifndef __ATOMIC_H__
#define __ATOMIC_H__

#include "posix_define.h"
#include "stdint.h"
// https://www.sohu.com/a/116178431_464041
// https://blog.csdn.net/minCrazy/article/details/40791795
// https://blog.csdn.net/qiqll/article/details/7971574
// http://blog.chinaunix.net/uid-24774106-id-3016929.html
// https://blog.csdn.net/hzhsan/article/details/25124901

// gcc 的原子操作接口封装

__POSIX_THREAD_BEGIN

namespace detail
{

template <typename T>
class AtomicIntegerT
{
public:
  AtomicIntegerT(const AtomicIntegerT &atomic) = delete;
  AtomicIntegerT &operator=(const AtomicIntegerT &atomic) = delete;

  AtomicIntegerT()
      : value_(0)
  {
  }

  T get()
  {
    // in gcc >= 4.7: __atomic_load_n(&value_, __ATOMIC_SEQ_CST)
    // bool __sync_bool_compare_and_swap (type*ptr, type oldval, type newval, ...)
    // type __sync_val_compare_and_swap (type *ptr, type oldval,  type newval, ...)
    // 这两个函数提供原子的比较和交换，如果*ptr == oldval,就将newval写入*ptr,
    // 第一个函数在相等并写入的情况下返回true.
    // 第二个函数返回操作之前的值。
    return __sync_val_compare_and_swap(&value_, 0, 0);
  }

  T getAndAdd(T x)
  {
    // in gcc >= 4.7: __atomic_fetch_add(&value_, x, __ATOMIC_SEQ_CST)
    // 先取值, 后自增 , 相当于 i ++
    return __sync_fetch_and_add(&value_, x);
  }

  T addAndGet(T x)
  {
    return getAndAdd(x) + x;
  }

  T incrementAndGet()
  {
    return addAndGet(1);
  }

  T decrementAndGet()
  {
    return addAndGet(-1);
  }

  void add(T x)
  {
    getAndAdd(x);
  }

  void increment()
  {
    incrementAndGet();
  }

  void decrement()
  {
    decrementAndGet();
  }

  T getAndSet(T newValue)
  {
    // in gcc >= 4.7: __atomic_exchange_n(&value, newValue, __ATOMIC_SEQ_CST)
    // type __sync_lock_test_and_set (type *ptr, type value, ...)
    // 将 *ptr 设为 value 并返回 *ptr 操作之前的值
    return __sync_lock_test_and_set(&value_, newValue);
  }

private:
  // volatile(易变的) : 该变量不能优化，cpu 不能到相应线程寄存器中取该变量值，需要直接存取原始内存地址
  volatile T value_;
};

} // namespace detail

using AtomicInt32 = detail::AtomicIntegerT<int32_t>;
using AtomicInt64 = detail::AtomicIntegerT<int64_t>;

__POSIX_THREAD_END

#endif // __ATOMIC_H__