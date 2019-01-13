#ifndef __POSIX_DEFINE_H__
#define __POSIX_DEFINE_H__

#define __POSIX_THREAD_BEGIN namespace PosixThread {
#define __POSIX_THREAD_END }

/**
  * 
  * __builtin_expect() 是 GCC (version >= 2.96）提供给程序员使用的，目的是将“分支转移”的信息提供给编译器，
  * 这样编译器可以对代码进行优化，以减少指令跳转带来的性能下降。
  * __builtin_expect((x),1)表示 x 的值为真的可能性更大；
  * __builtin_expect((x),0)表示 x 的值为假的可能性更大。
  * 也就是说，使用likely()，执行 if 后面的语句的机会更大，使用 unlikely()，执行 else 后面的语句的机会更大。
  * 通过这种方式，编译器在编译过程中，会将可能性更大的代码紧跟着起面的代码，从而减少指令跳转带来的性能上的下降.
  * 
  */
#define likely(x) __builtin_expect(!!(x), 1)   // x很可能为真  编译器会将可能性     
#define unlikely(x) __builtin_expect(!!(x), 0) // x很可能为假


// Macro for noexcept, to support in mixed 03/0x mode.
#ifndef _T_NOEXCEPT
# if __cplusplus >= 201103L
#  define _T_NOEXCEPT noexcept
#  define _T_USE_NOEXCEPT noexcept
#  define _T_THROW(_EXC)
# else
#  define _T_NOEXCEPT
#  define _T_USE_NOEXCEPT throw()
#  define _T_THROW(_EXC) throw(_EXC)
# endif
#endif

#endif // !__POSIX_DEFINE_H__