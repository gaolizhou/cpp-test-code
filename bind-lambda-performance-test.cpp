//
// Created by lizgao on 7/27/18.
//

#include <functional>
#include <glog/logging.h>

namespace {
class Data {
 public:
  int Add(int x, int y) {
    return x+y + base_;
  }
 private:
  int base_ = 100;
};

}

void bind_lambda_performace_test() {



}