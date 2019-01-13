# **posix-thread-cplusplus**

## 工程介绍
本工程只要是对陈硕老师`muduo`网络库中的多线程部分的代码，进行分析和测试，并将陈硕老师的封装思路和注意点加入到注释中，方便自己查阅，自己编写一遍代码主要是为了加深自己对多线程编程的理解。

代码中主要包括 `MutexLock`, `MutexLockGuard`, `Condition`, `AtomicIntegerT`, `CountDownLatch`, `Thread` 等多线程构件。 使用 `C++` 语言进行编写封装，以达到线程资源以`OOP`思维进行管理和使用。

## 测试框架
> googletest 

## 源码介绍
**3rdlib**
> googletest库

**build**
> Cmake 构件目录

**src**
> 多线程封装源码

**unit_mock**
> googlemock 测试，和该项目无关

**unit_test**
> googletest 测试多线程源码

## 构建
工程构建采用的是 `cmake` ，使用起来很方便!

**1. 创建构建目录 (在源代码目录创建即可)**
> bash-4.2$ mkdir build

**2. 构建指令**
> bash-4.2$ cd build

> bash-4.2$ cmake .. -DENABLE_TEST=ON （有加入一个编译宏 ENABLE_TEST）

> bash-4.2$ make install

**3. 执行即可 (可执行文件在：build/output/bin/)**
> bash-4.2$ ./output/bin/posix_thread_test.exx

