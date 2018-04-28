//
// Created by lizgao on 4/26/18.
//

#include <vector>
#include <memory>
#include <glog/logging.h>


void unique_ptr_nullptr() {

  auto x = std::unique_ptr<int>();
  LOG(INFO) << "ptr=" << x.get();
  auto y = std::unique_ptr<int>(new int(5));
  LOG(INFO) << "ptr=" << y.get();
}