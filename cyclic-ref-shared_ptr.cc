//
// Created by lizgao on 4/3/18.
//
#include <memory>
#include <string>
#include "glog/logging.h"
namespace {

template <typename T>
struct CyclicSharedPtr {
  std::shared_ptr<T> ptr_;


  CyclicSharedPtr(const CyclicSharedPtr<T> &cyc_ptr) {
    ptr_ = cyc_ptr.ptr_;
    LOG(INFO) << "copy construct";
  }
  CyclicSharedPtr& operator=(const CyclicSharedPtr<T> &cyc_ptr) {
    ptr_ = cyc_ptr.ptr_;
    LOG(INFO) << "assign construct";
    return *this;
  }

};

}