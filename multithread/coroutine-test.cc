//
// Created by lizgao on 1/26/19.
//
#include <glog/logging.h>
#include <functional>

namespace {

//current running coroutine
class Scheduler {

};


class Coroutine {
 public:
  Coroutine(const std::function<void(void)> &fun) : fun_(fun){

  }
  ~Coroutine() {

  }
 public:
  static void Yield() {
    LOG(INFO) << "Yield";
  }
  void Resume() {
    LOG(INFO) << "Resume";
  }
 private:
  std::function<void(void)> fun_;
};



void fun() {
  for(int i = 0; i< 10; i++) {
    LOG(INFO) << "fun " << i;
    Coroutine::Yield();
  }
}

void fun2() {
  for(int i = 0; i< 10; i++) {
    LOG(INFO) << "fun2 " << i;
    Coroutine::Yield();
  }
}
}

void coroutine_test2() {
  Coroutine coro(fun);
  coro.Resume();

  Coroutine coro2(fun2);
  coro2.Resume();

}