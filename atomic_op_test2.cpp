//
// Created by lizgao on 7/14/18.
//
#include <cstdint>
#include <thread>
#include <atomic>
#include <glog/logging.h>

namespace {
constexpr int CNT = 10000000;
//int global_data = 0;
std::atomic_int global_data = {0};
void ThreadFun() {
  for(int i=0; i<CNT; i++){
    ++global_data;
    //global_data.store(global_data.load() + 1);
  }
}
}

void atomic_op_test2() {
  LOG(INFO) << "Start value=" << global_data;
  std::thread tid_read = std::thread(&ThreadFun);
  std::thread tid_write = std::thread(&ThreadFun);

  tid_read.join();
  tid_write.join();
  LOG(INFO) << "value = " << global_data;
}
//
// Created by lizgao on 7/14/18.
//

