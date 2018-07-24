//
// Created by lizgao on 7/24/18.
//
#include <cstdlib>
#include <thread>
#include <glog/logging.h>
namespace {


bool flag = false;

void thread_write() {
  usleep(10000);
  flag = true;
  LOG(INFO) << "set done flag = " << flag;
  usleep(100000000);
}

void thread_read() {
  while(!flag);
  LOG(INFO) << "flag = " << flag;
}

}

void multiple_thread_cpu_cache_test() {
  std::thread tid_read(&thread_read);
  std::thread tid_write(&thread_write);

  tid_write.join();
  tid_read.join();
}