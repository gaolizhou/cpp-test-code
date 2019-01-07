//
// Created by lizgao on 12/29/18.
//

#include <glog/logging.h>
#include <thread>
namespace {

void thread_fun() {
  int a[100];
  for (int i = 0; i < 100; ++i) {
    a[i] = i;
  }
  int sum = 0;
  for (int j = 0; j < 100; ++j) {
    sum += a[j];
  }
  sleep(10);
  LOG(INFO) << "sum = " << sum << ", sum_addr=" << &sum << ", a_addr=" << a;
}

}

void memlayout() {
  std::thread tid[10];
  for (int i = 0; i < 10; ++i) {
    tid[i] = std::thread(&thread_fun);
  }

  for (int j = 0; j < 10; ++j) {
    tid[j].join();
  }
}

/*
00007f3fce07e000       4       0       0 -----   [ anon ]
00007f3fce07f000    8192       8       8 rw---   [ anon ]
00007f3fce87f000       4       0       0 -----   [ anon ]
00007f3fce880000    8192       8       8 rw---   [ anon ]
00007f3fcf080000       4       0       0 -----   [ anon ]
00007f3fcf081000    8192       8       8 rw---   [ anon ]
00007f3fcf881000       4       0       0 -----   [ anon ]
00007f3fcf882000    8192       8       8 rw---   [ anon ]
00007f3fd0082000       4       0       0 -----   [ anon ]
00007f3fd0083000    8192       8       8 rw---   [ anon ]
00007f3fd0883000       4       0       0 -----   [ anon ]
00007f3fd0884000    8192       8       8 rw---   [ anon ]
00007f3fd1084000       4       0       0 -----   [ anon ]
00007f3fd1085000    8192       8       8 rw---   [ anon ]
00007f3fd1885000       4       0       0 -----   [ anon ]
00007f3fd1886000    8192       8       8 rw---   [ anon ]
00007f3fd2086000       4       0       0 -----   [ anon ]
00007f3fd2087000    8192       8       8 rw---   [ anon ]
00007f3fd2887000       4       0       0 -----   [ anon ]
00007f3fd2888000    8192       8       8 rw---   [ anon ]
 */