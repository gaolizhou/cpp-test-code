//
// Created by lizgao on 4/9/18.
//
#include <glog/logging.h>

void sanitize_test() {
  int *p = nullptr;
  *p = 10;
  LOG(INFO) << *p;
}

void sanitize_leak_test() {
  int *p = new int;
  *p = 10;
  LOG(INFO) << *p;
}