//
// Created by lizgao on 9/17/18.
//

#include <vector>
#include <map>
#include <glog/logging.h>
namespace {
}

void vector_gdb_test() {
  std::vector<std::pair<int, int>> a;
  LOG(INFO) << "cap=" << a.capacity();
  for (int i = 0;  i< 10; ++i) {
    a.push_back({i, 100-i});
  }
  LOG(INFO) << "cap=" << a.capacity();
}