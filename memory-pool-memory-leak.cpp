//
// Created by lizgao on 5/4/18.
//
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <cstdint>
#include <thread>
#include <glog/logging.h>

#include <boost/pool/pool_alloc.hpp>
namespace {
template <typename T>
struct Data {
 private:
  std::vector<T, boost::pool_allocator<T>> data;
 public:
  Data(int len) {
    data.reserve(len);
    for (int i = 0; i < len; ++i) {
      data.push_back(static_cast<T>(i));
    }
  }
  void clear() {
    data.clear();
  }
  ~Data() {
    
  }
};
}

void mem_pool_memory_leak_test() {
  const int CNT = 50000000;
  for (int j = 0; j < 30; ++j) {
    LOG(INFO) << "BEGIN";
    int cnt = CNT + rand()%1000;
    Data<int8_t> data(cnt);
    Data<int16_t> data2(cnt + 100);
    Data<int32_t> data3(cnt + 123);
    Data<int64_t> data4(cnt + 234);

    std::vector<std::unique_ptr<char[]>> d;
    for (int i = 0; i < 100; ++i) {
      d.emplace_back(std::unique_ptr<char[]>(new char[1000003]));
    }
    LOG(INFO) << "Finish cnt=";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    //std::cin.get();
    //for (int i = 0; i < CNT; ++i) {
    //  data[i].reset();
    //}
  }
  LOG(INFO) << "cnt = ";
  std::cin.get();
}
