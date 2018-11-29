//
// Created by lizgao on 11/18/18.
//

#include <glog/logging.h>
#include <functional>

namespace {
  void ff(int m) {
    LOG(INFO) << "BIND a=" << m;
  }

}


void lambda_delay_test() {
  int a = 200;
  auto f = [a]() {
    LOG(INFO) << "LAMBDA a=" << a;
  };

  ++a;
  auto f2 = std::bind(&ff, a);
  ++a;
  f();
  f2();
  LOG(INFO) << "MAIN a=" << a;

}
