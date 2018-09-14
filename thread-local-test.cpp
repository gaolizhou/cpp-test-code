//
// Created by lizgao on 9/10/18.
//

#include <thread>
#include <iostream>

#include <glog/logging.h>
namespace {
class CTest {
 public:
  CTest(void) {
    LOG(INFO) << "构造函数 this=" << this;
  }
  ~CTest(void) {
    LOG(INFO) << "析构函数 this=" << this;
  }
  void run(void) {
    LOG(INFO) << "调用函数 this=" << this;
  }
};
thread_local CTest g_test;

void FunThrd(void) {
  g_test.run();
}
}

void thread_local_test()
{
  LOG(INFO) << "start..";
  std::thread trd(FunThrd);
  std::thread trd2(FunThrd);
  trd.join();
  trd2.join();
  LOG(INFO) << "end..";
  g_test.run();
  g_test.run();
}