//
// Created by lizgao on 10/19/18.
//

#include <functional>
#include <array>
#include <vector>
#include <glog/logging.h>

namespace {

void async_fun(std::function<void(void)> cb) {
  cb();
  LOG(INFO) << "inner size=" << sizeof(cb);
}
template <class FUNC>
void async_fun2(FUNC cb) {
  cb();
  LOG(INFO) << "inner size=" << sizeof(cb);
}

void callback(const std::array<int, 1024> &v1, const std::array<int, 1024> &v2) {

  LOG(INFO) << "v1 size=" << v1.size();
  LOG(INFO) << "v2 size=" << v2.size();
}
struct Functor {

  void operator()() {
    LOG(INFO) << "functor v1 size=" << v1.size();
    LOG(INFO) << "functor v2 size=" << v2.size();
  }
  std::array<int, 1024> v1;
  std::array<int, 1024> v2;
};
}


void huge_lambda_cb_test() {
  std::array<int, 1024> v1 {1,2,3};
  std::array<int, 1024> v2 {11,22,33};

  auto cb = [=] {callback(v1, v2);};
  LOG(INFO) << "cb size=" << sizeof(cb);
  async_fun(cb);

  Functor cb2;
  LOG(INFO) << "cb2 size=" << sizeof(cb2);
  async_fun(cb2);

  async_fun2(cb);
  async_fun2(cb2);

  auto cb_bind = std::bind(callback, v1, v2);
  LOG(INFO) << "cb_bind size=" << sizeof(cb_bind);
  async_fun(cb_bind);
  async_fun2(cb_bind);
}