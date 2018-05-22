//
// Created by lizgao on 5/22/18.
//

#include <functional>
#include <glog/logging.h>

namespace {

void fun1(int x) {
  LOG(INFO) << "x=" << x;
}

void fun2(std::function<void(void)> f, int y) {
  f();
  LOG(INFO) << "y=" << y;
}

}
void bind_inside() {
  auto f1 = std::bind(&fun1, 1);
  std::function<void(void)> f11 = std::bind(&fun1, 1);
  auto f = std::bind(&fun2, std::function<void(void)>(std::bind(&fun1, 1)), std::placeholders::_1);
  f(2);
  fun2(f1, 3);
  fun2(f11, 4);
}