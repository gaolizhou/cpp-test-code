//
// Created by lizgao on 11/29/18.
//

#include <cstdint>
#include <atomic>
#include <mutex>
#include <glog/logging.h>
namespace {
constexpr uint64_t ITER = 1000000000ULL;
uint64_t normal_loop(int limit) {
  uint64_t value = 0;
  for (int i = 0; i < limit; ++i) {
    ++value;
  }
  return value;
}

uint64_t volatile_loop(int limit) {
  volatile uint64_t value = 0;
  for (int i = 0; i < limit; ++i) {
    ++value;
  }
  return value;
}

uint64_t atomic_loop(int limit) {
  std::atomic<uint64_t> value{0};
  for (int i = 0; i < limit; ++i) {
    ++value;
  }
  return value;
}

uint64_t atomic_relaxed_loop(int limit) {
  std::atomic<uint64_t> value{0};
  for (int i = 0; i < limit; ++i) {
    value.fetch_add(1, std::memory_order_relaxed);
  }
  return value;
}

uint64_t mutex_loop(int limit) {
  std::mutex mu;
  uint64_t value = 0;
  for (int i = 0; i < limit; ++i) {
    mu.lock();
    ++value;
    mu.unlock();
  }
  return value;
}


}
void atomic_cost_test() {
  LOG(INFO) << "Start";
  LOG(INFO) << "normal_loop = " << normal_loop(ITER);
  LOG(INFO) << "volatile_loop = " << volatile_loop(ITER);
  LOG(INFO) << "atomic_loop = " << atomic_loop(ITER);
  LOG(INFO) << "atomic_relaxed_loop = " << atomic_relaxed_loop(ITER);
  LOG(INFO) << "mutex_loop = " << mutex_loop(ITER);
}
