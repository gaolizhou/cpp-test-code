//
// Created by lizgao on 10/23/18.
//

#include <glog/logging.h>
#include <memory>
#include <map>
#include <thread>
namespace {

bool stop = false;
class Connection {
 public:


 private:
  int id_;
};


class ConnectionManager {
 public:
  void UpdateConnection(int id) {

  }
  void CheckCallback() {

  }

 private:
  std::map<int, std::shared_ptr<Connection>> conn_map_;
};


void thread_poor_man_timer(const std::function<void(void)> &cb) {
  while(!stop) {
    usleep(1000);
    cb();
  }
}

}

void timewheel_test() {
  constexpr int TIMEOUT = 10;
  std::thread timer_thread = std::thread();
}