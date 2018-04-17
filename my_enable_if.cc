//
// Created by lizgao on 3/27/18.
//
#include <type_traits>
#include <iostream>

namespace {
template<bool, typename T>
struct my_enable_if {
};

template<typename T>
struct my_enable_if<true, T> {
  using type = T;
};

template<typename T>
typename my_enable_if<std::is_integral<T>::value, void>::type
foo() {
  std::cout << "int foo" << std::endl;
};
//# if 0
template<typename T>
void foo() {
  std::cout << "other foo" << std::endl;
};
//#endif
}

void my_enable_if_test() {
  foo<float>();
 // foo<int>();
}