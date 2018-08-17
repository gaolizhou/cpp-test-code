//
// Created by lizgao on 8/2/18.
//

#include <benchmark/benchmark.h>
#include <glog/logging.h>

namespace {
}

static void BM_Glog(benchmark::State& state) {
  for (auto _ : state) {
    //LOG(INFO) << "hello world!";
  }
}
BENCHMARK(BM_Glog);
