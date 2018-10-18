//
// Created by lizgao on 10/17/18.
//
#include <glog/logging.h>
#include <functional>

namespace {




}

template <class F>
struct Wrapper {
  Wrapper(F f): f_(f) {
    LOG(INFO) << "in constructor!";
  }
  ~Wrapper() {
    LOG(INFO) << "in destructor!";
  }
  template <class... Args>
  typename std::result_of<F(Args...)>::type operator()(Args... args) {
    LOG(INFO) << "in operator!";
    return f_(std::forward<Args>(args)...);
  }
  F f_;
};

void var_args_test() {
  auto f1 = [](int x) {
    LOG(INFO) << "f1!";
    LOG(INFO) << __func__ << ", line=" << __LINE__;
  };


  Wrapper<decltype(f1)> w(f1);

  w(1);
}


