//
// Created by lizgao on 5/6/18.
//

#include <iostream>
#include <future>
#include <glog/logging.h>
namespace {
class A {
 public:
  void f(int *a, int *b) {
    LOG(INFO) <<std::hex << "a=" << a<< ",b=" << b;
    std::cout << "f::()" << std::endl;
    *b = *a;
  }
  std::future<void> Asyncf(int *a, int *b) {
    LOG(INFO) <<std::hex << "a=" << a<< ",b=" << b;
    std::future<void> i = std::async(std::launch::async, [&]() {
      f(a, b);
    });
    return i;
  }
};

}
void jiyou_problem() {
  A a;
  int x = 0, y = 0;
  auto ret = a.Asyncf(&x, &y);
  ret.get();
}
