//
// Created by lizgao on 4/8/18.
//
#include <memory>
#include <glog/logging.h>
void shared_ptr_test() {
  auto x = std::make_shared<int>(100);
  auto y = std::shared_ptr<int>(new int(10));

  LOG(INFO) << *x * (*y) ;
}