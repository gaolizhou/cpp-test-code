//
// Created by lizgao on 5/11/18.
//

#include <thread>
#include <glog/logging.h>

namespace {

int *p = nullptr;

void thread_fun1() {
  int x = 0;
  p = &x;

  while (true) {
    LOG(INFO) << "x=" << x;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

}

void thread_fun2() {

  while (true) {
    if (p) {
      (*p)++;
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

}

}

void thread_local_variable() {
  std::thread tid1(thread_fun1);
  std::thread tid2(thread_fun2);
  //tid1.join();
  //tid2.join();
  tid1.detach();
  tid2.detach();
}