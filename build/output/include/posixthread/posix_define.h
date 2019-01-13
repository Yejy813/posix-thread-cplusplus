#ifndef __POSIX_DEFINE_H__
#define __POSIX_DEFINE_H__

#define __POSIX_THREAD_BEGIN namespace PosixThread {
#define __POSIX_THREAD_END }

/**
  * 
  * __builtin_expect() �� GCC (version >= 2.96���ṩ������Աʹ�õģ�Ŀ���ǽ�����֧ת�ơ�����Ϣ�ṩ����������
  * �������������ԶԴ�������Ż����Լ���ָ����ת�����������½���
  * __builtin_expect((x),1)��ʾ x ��ֵΪ��Ŀ����Ը���
  * __builtin_expect((x),0)��ʾ x ��ֵΪ�ٵĿ����Ը���
  * Ҳ����˵��ʹ��likely()��ִ�� if ��������Ļ������ʹ�� unlikely()��ִ�� else ��������Ļ������
  * ͨ�����ַ�ʽ���������ڱ�������У��Ὣ�����Ը���Ĵ������������Ĵ��룬�Ӷ�����ָ����ת�����������ϵ��½�.
  * 
  */
#define likely(x) __builtin_expect(!!(x), 1)   // x�ܿ���Ϊ��  �������Ὣ������     
#define unlikely(x) __builtin_expect(!!(x), 0) // x�ܿ���Ϊ��


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