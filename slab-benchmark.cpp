//
// Created by lizgao on 7/24/18.
//
#include <glog/logging.h>
#include <unordered_set>
#include "get_clock.h"
namespace {

template<class T, int CHUNK_CNT>
class Slab {
  using value_type = T;
 public:
  Slab() {
    free_list_size_ = 0;
    for (int i = 0; i < CHUNK_CNT; ++i) {
      free_list_[free_list_size_++] = &value_[i];
    }
  }
  ~Slab() = default;
 public:
  value_type *Malloc() {
    if (free_list_size_ == 0) {
      return nullptr;
    }
    return free_list_[--free_list_size_];
  }
  void Free(value_type *p) {
    free_list_[free_list_size_++] = p;
  }
 private:
  value_type *free_list_[CHUNK_CNT];
  int free_list_size_ = 0;
 private:
  value_type value_[CHUNK_CNT];
};

struct Data {
  int x[10];
};
}

void slab_benchmark() {
  double mhz = get_cpu_mhz(0);
  std::unordered_set<Data*> hold_set;
  Slab<Data, 10000> pool;
  Data *ptr[10000];
  auto begin = get_cycles();
  for (int i = 0; i < 100; ++i) {
    ptr[i] = pool.Malloc();
    hold_set.insert(ptr[i]);
  }
  auto end = get_cycles();
  for (int i = 0; i < 100; ++i) {
    ptr[i] = (Data*)malloc(sizeof(Data));
  }
  auto end2 = get_cycles();
  LOG(INFO) << "time = " << (end-begin)/mhz << ", " << (end2-end)/mhz;
  auto end3 = get_cycles();
  LOG(INFO) << "hello world!";
  auto end4 = get_cycles();
  LOG(INFO) << "time = " << (end-begin)/mhz << ", " << (end2-end)/mhz << ","<<(end3-end)/mhz << ","<<(end4-end)/mhz;
}