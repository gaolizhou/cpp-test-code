//
// Created by lizgao on 9/3/18.
//
#include <glog/logging.h>

namespace {

class B1 {
 public:
  virtual void b1_fun() = 0;
 protected:
  int b1;
};
class B2 {
 public:
  virtual void b2_fun() = 0;
 protected:
  int b2;
};

class D : public B1, public B2 {
 public:
  void b1_fun() override {
    LOG(INFO) << __func__;
  }
  void b2_fun() override {
    LOG(INFO) << __func__;
  }
  void fun() {
    LOG(INFO) << "this=" << this;
    LOG(INFO) << "b1=" << &b1;
    LOG(INFO) << "b2=" << &b2;
    LOG(INFO) << "d=" << &d;
  }
 private:
  int d;
};

}

void static_cast_test() {
  D d;
  auto b1 = static_cast<B1*>(&d);
  auto b2 = static_cast<B2*>(&d);
  b1->b1_fun();
  b2->b2_fun();
  d.fun();
  void *p = &d;
  auto b22 = static_cast<B2*>(p);
  b22->b2_fun();

}
