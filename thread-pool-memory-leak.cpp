//
// Created by lizgao on 5/4/18.
//

#include "ThreadPool.h"
#include <memory>
#include <vector>
#include <iostream>
#include <string>
#include <glog/logging.h>

namespace {
constexpr int CNT = 50000000;
class Data {
 public:
  Data() { data_.reserve(CNT); LOG(INFO) << "construct" ;}
  ~Data() {LOG(INFO) << "destroy" ;}
 public:
  std::vector<std::string> data_;
};
void fun(std::shared_ptr<Data> buff) {
  LOG(INFO) << "ref-cnt=" << buff.use_count();
  for (int i = 0; i < CNT; ++i) {
    buff->data_.push_back(std::to_string(i));
  }
  std::this_thread::sleep_for(std::chrono::seconds(1));
}


}

void thread_pool_memory_leak() {
  ThreadPool pool(1);
  std::vector<std::shared_ptr<Data>> data_list;
  for (int j = 0; j < 20; ++j) {
    data_list.push_back(std::make_shared<Data>());
  }
  for(int i = 0; i < 20; ++i) {
    pool.enqueue(fun, std::move(data_list[i]));
  }

  std::cin.get();
}