//
// Created by lizgao on 1/24/19.
//

#include <glog/logging.h>
#include <future>

namespace {
void fun() {
  usleep(1000000);
  LOG(INFO) << "I am fun";
}

}

void async_test() {
  auto fu = std::async(std::launch::deferred, fun);
  LOG(INFO) << "main thread";
  fu.get();
  sleep(2);
  LOG(INFO) << "main end";
}

void async_test2() {
  auto fu = std::async(std::launch::async, fun);
  LOG(INFO) << "main thread";
  fu.get();
  sleep(2);
  LOG(INFO) << "main end";
}