//
// Created by lizgao on 4/11/18.
//

#include <array>
#include <iostream>
namespace {

class B {
 public:
  //explicit B(int x) : x_(x) {}

  void fun() {
    std::cout << "x=" << x_ << std::endl;
  }

 private:
  int x_;
};

}

void std_array_test() {
  std::array<B, 60> b_list_;

  for (auto &b : b_list_) {
    b.fun();
  }

}