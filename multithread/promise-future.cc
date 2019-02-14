//
// Created by lizgao on 1/31/19.
//

#include <future>
#include <thread>
#include <chrono>
#include <glog/logging.h>
namespace {
void callback(std::promise<void> p) {
  LOG(INFO) << "Enter callback!";
  std::this_thread::sleep_for(std::chrono::seconds(1));
  p.set_value();
  LOG(INFO) << "I am ready!";
}
}

void promise_future_test() {
  std::promise<void> p;
  std::future<void> f = p.get_future();
  LOG(INFO) << "async run callback! -1";
  auto x = std::async(std::launch::async, callback, std::move(p));
  //auto x = std::async(std::launch::async, callback);
  //auto tid = std::thread(callback, std::move(p));
  LOG(INFO) << "async run callback! -2";
//  while(f.wait_for(std::chrono::seconds(0)) != std::future_status::ready) {
//    LOG(INFO) << "not ready!";
//    std::this_thread::sleep_for(std::chrono::milliseconds(100));
//  }
  LOG(INFO) << "target is ready! -1 ";
  f.get();
  LOG(INFO) << "target is ready! -2";
  //tid.join();
}