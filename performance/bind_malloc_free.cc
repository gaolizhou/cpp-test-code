//
// Created by lizgao on 11/14/18.
//
#include <glog/logging.h>
#include <functional>


namespace bind_test {

int caller(std::function<int()> cb) {
  //LOG(INFO) << cb();
  return cb() + 2;
}

template <class FUN>
int callerTemp(FUN cb) {
  return cb() + 2;
}

int  f3() {
  int data_inside [100];
  int len_inside = 100;
  int sum = 0;
  for (int i = 0; i < len_inside; ++i) {
    sum += data_inside [i];
  }
  return sum;
}
}

void bind_memory_test() {
  int data[100];
  int len = 100;
  for (int i = 0; i < len; ++i) {
    data [i] = i;
  }
  auto f = [=]() -> int {
    int sum = 0;
    for (int i = 0; i < len; ++i) {
      sum += data [i];
    }
    return sum;
  };
  auto f2 = []() -> int {
    int data_inside [100];
    int len_inside = 100;
    int sum = 0;
    for (int i = 0; i < len_inside; ++i) {
      sum += data_inside [i];
    }
    return sum;
  };

  //bind_test::caller(f);
 // bind_test::caller(f2);
  bind_test::caller(bind_test::f3);
  bind_test::callerTemp(f);

  std::function<int()> cb = f2;
  cb();

/*
  LOG(INFO) << "size=" << sizeof(std::function<void(void)>);
  LOG(INFO) << "size=" << sizeof(std::function<void(int)>);
  LOG(INFO) << "size=" << sizeof(std::function<void(int, int)>);
  LOG(INFO) << "size=" << sizeof(std::function<void(int64_t, int64_t)>);
  std::function<int64_t(int64_t, int64_t, int64_t, int64_t, int64_t)> f5;
  LOG(INFO) << "size=" << sizeof(std::function<int64_t(int64_t, int64_t, int64_t, int64_t, int64_t)>);
*/
}
/*
(gdb) b malloc
Breakpoint 1 at 0x406f90
(gdb) b free
Breakpoint 2 at 0x407230
(gdb) commands 1 2
Type commands for breakpoint(s) 1 2, one per line.
End with a line saying just "end".
>bt
>c
>end
(gdb) set pagination off
(gdb) disable 1 2
(gdb) b bind_memory_test
Breakpoint 3 at 0x43dd05: file /home/lizgao/dev/cpp-test-code/performance/bind_malloc_free.cc, line 19.
(gdb) r
Starting program: /home/lizgao/dev/cpp-test-code/cmake-build-debug/cmake_test
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib64/libthread_db.so.1".

Breakpoint 3, bind_memory_test () at /home/lizgao/dev/cpp-test-code/performance/bind_malloc_free.cc:19
19        int len = 100;
Missing separate debuginfos, use: debuginfo-install glibc-2.17-222.el7.x86_64 leveldb-1.12.0-11.el7.x86_64 libevent-2.0.21-4.el7.x86_64 libgcc-4.8.5-28.el7_5.1.x86_64 libstdc++-4.8.5-28.el7_5.1.x86_64 snappy-1.1.0-3.el7.x86_64
(gdb) enable 1 2
(gdb) c
Continuing.

Breakpoint 1, 0x00007ffff6991800 in malloc () from /lib64/libc.so.6
#0  0x00007ffff6991800 in malloc () from /lib64/libc.so.6
#1  0x00007ffff724fecd in operator new(unsigned long) () from /lib64/libstdc++.so.6
#2  0x000000000043dfb1 in std::_Function_base::_Base_manager<bind_memory_test()::__lambda0>::_M_init_functor(std::_Any_data &, <unknown type in /home/lizgao/dev/cpp-test-code/cmake-build-debug/cmake_test, CU 0x21a2ad, DIE 0x21f9eb>, std::false_type) (__functor=..., __f=<unknown type in /home/lizgao/dev/cpp-test-code/cmake-build-debug/cmake_test, CU 0x21a2ad, DIE 0x21f9eb>) at /usr/include/c++/4.8.2/functional:1987
#3  0x000000000043debf in std::_Function_base::_Base_manager<bind_memory_test()::__lambda0>::_M_init_functor(std::_Any_data &, <unknown type in /home/lizgao/dev/cpp-test-code/cmake-build-debug/cmake_test, CU 0x21a2ad, DIE 0x21f9eb>) (__functor=..., __f=<unknown type in /home/lizgao/dev/cpp-test-code/cmake-build-debug/cmake_test, CU 0x21a2ad, DIE 0x21f9eb>) at /usr/include/c++/4.8.2/functional:1958
#4  0x000000000043de43 in std::function<int()>::function<bind_memory_test()::__lambda0, void>(__lambda0) (this=0x7fffffffe310, __f=...) at /usr/include/c++/4.8.2/functional:2458
#5  0x000000000043dda9 in bind_memory_test () at /home/lizgao/dev/cpp-test-code/performance/bind_malloc_free.cc:30
#6  0x00000000004084c6 in main () at /home/lizgao/dev/cpp-test-code/main.cpp:32

Breakpoint 2, 0x00007ffff6991c20 in free () from /lib64/libc.so.6
#0  0x00007ffff6991c20 in free () from /lib64/libc.so.6
#1  0x000000000043e167 in std::_Function_base::_Base_manager<bind_memory_test()::__lambda0>::_M_destroy(std::_Any_data &, std::false_type) (__victim=...) at /usr/include/c++/4.8.2/functional:1926
#2  0x000000000043df78 in std::_Function_base::_Base_manager<bind_memory_test()::__lambda0>::_M_manager(std::_Any_data &, const std::_Any_data &, std::_Manager_operation) (__dest=..., __source=..., __op=std::__destroy_functor) at /usr/include/c++/4.8.2/functional:1950
#3  0x000000000040de15 in std::_Function_base::~_Function_base (this=0x7fffffffe310, __in_chrg=<optimized out>) at /usr/include/c++/4.8.2/functional:2030
#4  0x0000000000414f20 in std::function<int ()>::~function() (this=0x7fffffffe310, __in_chrg=<optimized out>) at /usr/include/c++/4.8.2/functional:2174
#5  0x000000000043ddc1 in bind_memory_test () at /home/lizgao/dev/cpp-test-code/performance/bind_malloc_free.cc:30
#6  0x00000000004084c6 in main () at /home/lizgao/dev/cpp-test-code/main.cpp:32

Breakpoint 2, 0x00007ffff6991c20 in free () from /lib64/libc.so.6
#0  0x00007ffff6991c20 in free () from /lib64/libc.so.6
#1  0x00007ffff72aec03 in std::basic_string<char, std::char_traits<char>, std::allocator<char> >::~basic_string() () from /lib64/libstdc++.so.6
#2  0x00007ffff6945bd9 in __run_exit_handlers () from /lib64/libc.so.6
#3  0x00007ffff6945c27 in exit () from /lib64/libc.so.6
#4  0x00007ffff692e44c in __libc_start_main () from /lib64/libc.so.6
#5  0x00000000004083f1 in _start ()

Breakpoint 2, 0x00007ffff6991c20 in free () from /lib64/libc.so.6
#0  0x00007ffff6991c20 in free () from /lib64/libc.so.6
#1  0x00007ffff72aec03 in std::basic_string<char, std::char_traits<char>, std::allocator<char> >::~basic_string() () from /lib64/libstdc++.so.6
#2  0x00007ffff6945bd9 in __run_exit_handlers () from /lib64/libc.so.6
#3  0x00007ffff6945c27 in exit () from /lib64/libc.so.6
#4  0x00007ffff692e44c in __libc_start_main () from /lib64/libc.so.6
#5  0x00000000004083f1 in _start ()

Breakpoint 2, 0x00007ffff6991c20 in free () from /lib64/libc.so.6
#0  0x00007ffff6991c20 in free () from /lib64/libc.so.6
#1  0x00007ffff6945c00 in __run_exit_handlers () from /lib64/libc.so.6
#2  0x00007ffff6945c27 in exit () from /lib64/libc.so.6
#3  0x00007ffff692e44c in __libc_start_main () from /lib64/libc.so.6
#4  0x00000000004083f1 in _start ()

Breakpoint 2, 0x00007ffff6991c20 in free () from /lib64/libc.so.6
#0  0x00007ffff6991c20 in free () from /lib64/libc.so.6
#1  0x00007ffff72aec03 in std::basic_string<char, std::char_traits<char>, std::allocator<char> >::~basic_string() () from /lib64/libstdc++.so.6
#2  0x0000000000445155 in fLS::StringFlagDestructor::~StringFlagDestructor() ()
#3  0x00007ffff6945bd9 in __run_exit_handlers () from /lib64/libc.so.6
#4  0x00007ffff6945c27 in exit () from /lib64/libc.so.6
#5  0x00007ffff692e44c in __libc_start_main () from /lib64/libc.so.6
#6  0x00000000004083f1 in _start ()
[Inferior 1 (process 6886) exited normally]
(gdb)
 */

