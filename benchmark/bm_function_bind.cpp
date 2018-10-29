//
// Created by lizgao on 7/27/18.
//

#include <benchmark/benchmark.h>
#include <unordered_set>
#include <unordered_map>

namespace {
void async_fun(std::function<void(void)> cb) {
  cb();
}
template <class FUNC>
void async_fun2(FUNC cb) {
  cb();
}

void callback(const std::array<int, 1024> &v1, const std::array<int, 1024> &v2) {

}
struct Functor {

  void operator()() {
  }
  std::array<int, 1024> v1;
  std::array<int, 1024> v2;
};

}

static void BM_Function_Bind1(benchmark::State& state) {
  std::array<int, 1024> v1 {1,2,3};
  std::array<int, 1024> v2 {11,22,33};

  auto cb = [=] {callback(v1, v2);};

  for (auto _ : state) {
    async_fun(cb);
  }
}
static void BM_Function_Bind2(benchmark::State& state) {
  std::array<int, 1024> v1 {1,2,3};
  std::array<int, 1024> v2 {11,22,33};
  auto cb_bind = std::bind(callback, v1, v2);
  for (auto _ : state) {
    async_fun(cb_bind);
  }
}
static void BM_Function_Bind3(benchmark::State& state) {
  std::array<int, 1024> v1 {1,2,3};
  std::array<int, 1024> v2 {11,22,33};
  auto cb_bind = std::bind(callback, v1, v2);

  for (auto _ : state) {
    async_fun2(cb_bind);
  }
}
BENCHMARK(BM_Function_Bind1);
BENCHMARK(BM_Function_Bind2);
BENCHMARK(BM_Function_Bind3);
