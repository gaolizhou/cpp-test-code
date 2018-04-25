//
// Created by lizgao on 4/25/18.
//
#include <iostream>

namespace {

class Base {
 public:
  Base() : x_(0), y_(0) {}
  Base(int x) : x_(x), y_(0) {

  }
  Base(int x, int y) : x_(x), y_(y) {

  }
  void fun() {
    std::cout << "x=" << x_ << ", y=" << y_ << std::endl;
  }
 private:
  int x_;
  int y_;
};

class Derive : public Base {
using Base::Base;
};

}

void using_base_constructor_test() {

  Derive d;
  Derive d2(1);
  Derive d3(1,2);
  d.fun();
  d2.fun();
  d3.fun();

}