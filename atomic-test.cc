//
// Created by lizgao on 4/12/18.
//

#include <atomic>
#include <mutex>
#include <iostream>
#include <chrono>
#include <thread>
namespace {
const size_t size = 100000000;
std::mutex mutex;
bool var = false;

typedef std::chrono::high_resolution_clock Clock;

void testA() {
  std::atomic<bool> sync(true);
  const auto start_time = Clock::now();
  for (size_t counter = 0; counter < size; counter++) {
    sync.store(!sync.load());
    //var = sync.load();
    //sync.store(true);
    //sync.exchange(true);
  }
  const auto end_time = Clock::now();
  std::cout << 1e-6 * std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " s\n";
}

void testB() {
  const auto start_time = Clock::now();
  for (size_t counter = 0; counter < size; counter++) {
    std::unique_lock<std::mutex> lock(mutex);
    var = !var;
  }
  const auto end_time = Clock::now();
  std::cout << 1e-6 * std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " s\n";
}
}
void atomic_test()
{
  std::thread t1(testA);
  std::thread t11(testA);
  t1.join();
  t11.join();
  std::thread t2(testB);
  std::thread t22(testB);
  t2.join();
  t22.join();
}
