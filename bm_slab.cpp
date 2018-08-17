//
// Created by lizgao on 7/27/18.
//

#include <benchmark/benchmark.h>


namespace {

template <class T, int CHUNK_CNT>
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
  int x;
  int y;
  int z;
};
}
static void BM_Slab(benchmark::State& state) {
  Slab<Data, 2000> pool;
  Data *ptr[100];
  for (auto _ : state) {
    for (int i = 0; i < 100; ++i) {
      ptr[i] = pool.Malloc();
    }
    for (int i = 0; i < 100; ++i) {
      pool.Free(ptr[i]);
    }
  }
}
BENCHMARK(BM_Slab);

static void BM_Malloc(benchmark::State& state) {
  void *ptr[100];
  for (auto _ : state) {
    for (int i = 0; i < 100; ++i) {
      ptr[i] = malloc(1024);
    }
    for (int i = 0; i < 100; ++i) {
      free(ptr[i]);
    }
  }
}
BENCHMARK(BM_Malloc);

