//
// Created by lizgao on 8/23/18.
//
#include <unistd.h>
#include <mutex>
#include <thread>

namespace {
std::mutex mu;

void thread_fun() {
  mu.lock();
  sleep(1);
  mu.unlock();
}

}

void futex_test() {
  sleep(1);
  //thread_fun();
  std::thread tid1(thread_fun);
  std::thread tid2(thread_fun);
  tid1.join();
  tid2.join();
  sleep(1);
}