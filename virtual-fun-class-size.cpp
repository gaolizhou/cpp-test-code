//
// Created by lizgao on 5/10/18.
//
#include <glog/logging.h>
#include <cstdint>
namespace {
class B {

};
class B1 {
 public:
  virtual ~B1() {}
};
class B2 {
 public:
  virtual void fun1() {}
  virtual ~B2() {}
};
class B3 {
 public:
  virtual void fun1() {}
  virtual void fun2() {}
  virtual ~B3() {}
 private:
  int64_t x = 0x1234567812345678;
};


class B4 {
 public:
  virtual void fun1() {}
  virtual void fun2() {}
  virtual void fun3() {}
  virtual ~B4() {}
};

}

void virtual_fun_class_size() {
  LOG(INFO) << "size=" << sizeof(B);
  LOG(INFO) << "size=" << sizeof(B1);
  LOG(INFO) << "size=" << sizeof(B2);
  LOG(INFO) << "size=" << sizeof(B3);
  B3 b3;
  b3.fun1();
}