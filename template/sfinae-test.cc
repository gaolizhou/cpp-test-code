//
// Created by lizgao on 2/14/19.
//
#include <type_traits>
#include <glog/logging.h>
namespace {
template <typename T1, typename T2>
struct AddSpec {
  void operator()() {
    LOG(INFO) << "Common Version!";
  }
};

template <typename T1>
struct AddSpec <T1, int> {
  void operator()() {
    LOG(INFO) << "T2=int Version!";
  }
};

template <>
struct AddSpec <int, int> {
  void operator()() {
    LOG(INFO) << "T1=int T2=int Version!";
  }
};


template <typename T, typename T2=void>
struct AddSfinae {
  void operator()() {
    LOG(INFO) << "Common version!";
  }
};


template <typename T>
struct AddSfinae <T, typename std::enable_if<std::is_integral<T>::value>::type>{
  void operator()() {
    LOG(INFO) << "AddSfinae int version!";
  }
};


}


void sfinae_test2() {
  AddSpec<void, void>()();
  AddSpec<void, int>()();
  AddSpec<int, int>()();
  AddSfinae<float>()(); // float, void
  AddSfinae<int>()();
}
