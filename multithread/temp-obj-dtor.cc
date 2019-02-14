//
// Created by lizgao on 1/31/19.
//
#include <glog/logging.h>

namespace {
class Obj {
 public:
  Obj() {
    LOG(INFO) << "ctor";
  }
  ~Obj() {
    LOG(INFO) << "dtor";
  }
};
}

void temp_obj_dtor() {
  LOG(INFO) << "enter fun";
  Obj();
  LOG(INFO) << "leave fun";
}