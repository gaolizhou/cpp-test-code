//
// Created by lizgao on 3/31/19.
//
#include <glog/logging.h>
#include <functional>
#include <vector>
#include <thread>
#include <list>
#include <mutex>
#include <condition_variable>
namespace {
#if 0
class ThreadPool {
 public:
  ThreadPool(int pool_size):pool_size_(pool_size) {




  }
  ~ThreadPool() {

  }

  void push_task() {

  }
 private:
  void worker_run() {
    while(true) {
      std::unique_lock<std::mutex> lk(mu_);
      if(task_list_.empty()) {
        cond_.wait(lk, []() {});
      }

    }
  }
 private:
  int pool_size_;
  std::vector<std::thread> thread_list_;
  std::list<std::function<void(void)>> task_list_;
  std::condition_variable cond_;
  std::mutex mu_;

};
#endif
}

