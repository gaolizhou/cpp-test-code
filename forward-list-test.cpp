//
// Created by lizgao on 6/27/18.
//

#include <forward_list>
#include <algorithm>
#include <iostream>

namespace {

struct Data {
  int a;
  int b;
  int c;
  int d = 0x12345678;
  int64_t e = 0x8765432187654321;
  int64_t f = 0x8765432187654321;
  int64_t g = 0x8765432187654321;
  Data(int aa, int bb, int cc) : a(aa), b(bb), c(cc) {}
};

}

void forward_list_test() {

  std::forward_list<Data> data_list;
  data_list.emplace_front(1,1,1);
  data_list.emplace_front(2,2,2);
  data_list.emplace_front(3,3,3);
  data_list.emplace_front(4,4,4);
  data_list.emplace_front(5,5,5);
  data_list.emplace_front(6,6,6);

  std::for_each(data_list.begin(), data_list.end(), [](const Data &d){ std::cout << d.a << std::showbase << ", addr="  << &d << std::endl;});
  std::cout << "list_addr = " << std::showbase << &data_list << std::endl;
}