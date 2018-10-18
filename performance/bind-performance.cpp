//
// Created by lizgao on 10/18/18.
//
#include <array>
#include <functional>
#include <glog/logging.h>

void bind_performance_test() {
  std::array<uint, 5> data = {1,2,3,4,5};

  auto A = [=] () -> int {
    return (data[0] + data[1] * data[2] + data[3]) ^ data[4];
  };

// A dynamic memory allocation of sizeof(A) + some change is done on assignment
// sizeof(A) = 20 on my machine, and it ends up doing a 28 byte allocation from the heap.
  std::function<int(void)> fA = A;

// A virtual function is called to be able to execute A()
  int ret = fA();
  LOG(INFO) << "result=" << ret << ", size="<<sizeof(A) << "/" << sizeof(fA);
}