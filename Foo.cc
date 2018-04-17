//
// Created by lizgao on 3/27/18.
//

#include "Foo.h"
#include <iostream>
template <typename T> void Foo::fun() {
  std::cout << "Foo-fun" << std::endl;
}

template void Foo::fun<int>();