//
// Created by lizgao on 4/28/18.
//
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

namespace {

void fun(std::vector<int> &&v) {

  std::cout << std::string(80, 'v') << std::endl;
  for (auto e : v) {
    std::cout << e << std::endl;
  }
}
void fun2(std::vector<int> &&v) {
  auto y = std::move(v);
  std::cout << std::string(80, 'v') << std::endl;
  for (auto e : y) {
    std::cout << e << std::endl;
  }
}

void fun3(std::vector<int> v) {

  std::cout << std::string(80, 'v') << std::endl;
  for (auto e : v) {
    std::cout << e << std::endl;
  }
}
}


void move_vector_test() {
  std::vector<int> x {1,2,3,4,5,6,7,8};
  fun3(std::move(x));

  std::cout << std::string(80, '*') << std::endl;

  for (auto e : x) {
    std::cout << e << std::endl;
  }
}


void move_vector_test2() {
  std::vector<int> x {1,2,3,4,5,6,7,8};
  auto y = std::move(x);

  for (auto e : x) {
    std::cout << e << std::endl;
  }

  std::cout << std::string(80, '*') << std::endl;

  for (auto e : y) {
    std::cout << e << std::endl;
  }

}
