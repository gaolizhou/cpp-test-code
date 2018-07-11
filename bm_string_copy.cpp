//
// Created by lizgao on 7/11/18.
//
#include <cstdlib>
#include <memory.h>
#include <benchmark/benchmark.h>

static void BM_StringCreation(benchmark::State& state) {
  for (auto _ : state)
    std::string empty_string;
}
// Register the function as a benchmark
BENCHMARK(BM_StringCreation);

// Define another benchmark
static void BM_StringCopy(benchmark::State& state) {
  std::string x = "hello";
  for (auto _ : state)
    std::string copy(x);
}
BENCHMARK(BM_StringCopy);


static void BM_MemoryCopy(benchmark::State& state) {
  char dst[1024];
  char src[1024];
  for (auto _ : state) {
    memcpy(dst, src, sizeof(dst));
  }
}
BENCHMARK(BM_MemoryCopy);


