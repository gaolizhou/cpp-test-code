//
// Created by lizgao on 7/27/18.
//

#include <benchmark/benchmark.h>
#include <unordered_set>
#include <unordered_map>

namespace {
}

static void BM_Set(benchmark::State& state) {
  std::unordered_set<int> int_set;
  //int_set.rehash(100);
  for (auto _ : state) {
    for (int i = 0; i < 100; ++i) {
      int_set.insert(i);
    }
    for (int i = 0; i < 100; ++i) {
      int_set.erase(i);
    }
  }
}
BENCHMARK(BM_Set);
