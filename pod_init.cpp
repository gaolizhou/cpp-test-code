//
// Created by lizgao on 10/19/18.
//
#include <glog/logging.h>
#include <memory>

namespace {
class POD {
 public:
  int x;
  int y;
  int z;
  void fun() {}
};
}

void pod_init_test() {
  auto ptr = std::make_shared<POD>(POD{1,2,3});
  LOG(INFO) << "data=" << ptr->x << "," << ptr->y <<","<< ptr->z;
  POD pod { .x=2, .y=3, .z=4};
  LOG(INFO) << "data=" << pod.x << "," << pod.y <<","<< pod.z;
  POD pod2 = { .x=22, .y=23, .z=24};
  LOG(INFO) << "data=" << pod2.x << "," << pod2.y <<","<< pod2.z;
}