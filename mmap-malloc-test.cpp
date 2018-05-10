//
// Created by lizgao on 5/4/18.
//
#include <cstdlib>
#include <vector>
#include <array>
#include <iostream>
#include <thread>
#include <glog/logging.h>

void mmap_malloc_test() {

  void *p1 = malloc(64);
  void *p2 = malloc(100*1024);
  void *p3 = malloc(256*1024-10);
  void *p4 = malloc(100*1024);
  void *p5 = malloc(100*1024);
  void *p6 = malloc(100*1024);

  *reinterpret_cast<int*>(p1) = 0x12345678;
  *reinterpret_cast<int*>(p2) = 0x12345678;
  *reinterpret_cast<int*>(p3) = 0x12345678;
  *reinterpret_cast<int*>(p4) = 0x12345678;
  *reinterpret_cast<int*>(p5) = 0x12345678;
  *reinterpret_cast<int*>(p6) = 0x12345678;

  free(p1);
  free(p2);
  free(p3);
  free(p4);
  free(p5);
  free(p6);
  LOG(INFO) << "END";
  std::vector<int> data;
  data.reserve(100000);
  for (int i = 0; i < 100000; ++i) {
    data.push_back(i);
  }
}


void mmap_malloc_test2() {
  constexpr int64_t total_size = 2*1024*1024*1024ULL;
  constexpr int64_t ele_size = 100*1024*1024;
  constexpr int64_t cnt = total_size/ele_size + 1;
  std::array<char*, cnt> pt_list;

  for (int i = 0; i < cnt; ++i) {
    pt_list[i] = reinterpret_cast<char*>(malloc(ele_size));
    for (int j = 0; j < ele_size; ++j) {
      *(pt_list[i] + j) = '0';
    }
  }

  for (int i = 0; i < cnt; ++i) {
    free(pt_list[i]);
  }
  LOG(INFO) << "END";
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cin.get();

}

void mmap_malloc_test3() {
  constexpr int64_t total_size = 2*1024*1024*1024ULL;
  constexpr int64_t ele_size = 100*1024*1024;
  constexpr int64_t cnt = total_size/ele_size + 1;
  std::array<char*, cnt> pt_list;

  for (int i = 0; i < cnt; ++i) {
    pt_list[i] = reinterpret_cast<char*>(new char[ele_size]);
    for (int j = 0; j < ele_size; ++j) {
      *(pt_list[i] + j) = '0';
    }
  }

  for (int i = 0; i < cnt; ++i) {
    delete[] pt_list[i];
  }
  LOG(INFO) << "END";
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cin.get();

}