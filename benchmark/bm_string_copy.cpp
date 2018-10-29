//
// Created by lizgao on 7/11/18.
//
#include <cstdlib>
#include <memory.h>
#include <functional>
#include <benchmark/benchmark.h>
namespace {
class Data {
 public:
  int Add(int x, int y) {
    base_++;
    return x+y + base_;
  }
 private:
  int base_ = 100;
};

int Sub(int x, int y) {
  return x-y;
}


}

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

static void BM_Bind(benchmark::State& state) {
  Data data;
  auto f =  std::bind(&Data::Add, &data, 200, std::placeholders::_1);
  int result=0;
  for (auto _ : state) {
    result += f(10);
  }
}
BENCHMARK(BM_Bind);

static void BM_Lambda(benchmark::State& state) {
  Data data;
  auto f =  [&data](int x){ return data.Add(x, 200);};
  int result=0;
  for (auto _ : state) {
    result += f(10);
  }
}
BENCHMARK(BM_Lambda);

static void BM_Bind2(benchmark::State& state) {
  Data data;
  auto f =  std::bind(&Sub, 200, std::placeholders::_1);
  for (auto _ : state) {
    f(10);
  }
}
BENCHMARK(BM_Bind2);

static void BM_Lambda2(benchmark::State& state) {
  auto f =  [](int x){ return Sub(x, 200);};
  for (auto _ : state) {
    f(10);
  }
}
BENCHMARK(BM_Lambda2);





