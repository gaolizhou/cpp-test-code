//
// Created by lizgao on 11/27/18.
//
#include <glog/logging.h>

namespace {
class Base {
 public:
  virtual ~Base() {

  }
  virtual void fun() {
    LOG(INFO) << "Base Fun!";
  }
};

class Derived : public Base {
 public:
  ~Derived() override {

  }
  inline void fun() override {
    LOG(INFO) << "Derived Fun!";
  }
};

}

void derived_inline_virtual_function() {
  Derived d;
  d.fun();
  Base *b = &d;
  b->fun();
  Derived *pd = &d;
  pd->fun();
}