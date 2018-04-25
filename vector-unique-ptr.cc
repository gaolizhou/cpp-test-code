//
// Created by lizgao on 4/16/18.
//

#include <vector>
#include <memory>
#include <glog/logging.h>

using namespace std;
void vector_unique_ptr_test() {
  //vector<unique_ptr<int>> dd(8, nullptr);
  vector<unique_ptr<int>> xx(8);
  for (int i = 0; i < xx.size(); ++i) {
    xx[i] = nullptr;
  }

  LOG(INFO) << "size=" << xx.size();
}