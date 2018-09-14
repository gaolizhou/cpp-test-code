//
// Created by lizgao on 9/9/18.
//

#include <glog/logging.h>
namespace {
class Base {
 public:
  virtual ~Base() = default;

  virtual void fun1() = 0;
  virtual void fun2() = 0;
};

class D1 : public Base {
 public:
  ~D1() override = default;

  void fun1() override {
    LOG(INFO) << "D1 " << __func__;
  }

  void fun2() override {
    LOG(INFO) << "D1 " << __func__;
  }
};
}

void vptr_test() {
  D1 d1, d2;
  Base *b1 = &d1;
  Base *b2 = &d2;
  b1->fun1();
  b2->fun1();

  uint64_t p1;
  uint64_t p2;
  memcpy(&p1, b1, 8);
  memcpy(&p2, b2, 8);
  LOG(INFO) << "p1=" << p1;
  LOG(INFO) << "p2=" << p2;
  typedef void (*Funptr)(D1*);
  Funptr funptr;
  uint64_t * vptr = &(*(uint64_t *)p1);
  LOG(INFO) << "vptr=" << vptr;
  funptr = (Funptr)*(vptr + 2);
  //funptr = (Funptr)(&(*(uint64_t *)p1) + 1);
  funptr(&d1);

}
