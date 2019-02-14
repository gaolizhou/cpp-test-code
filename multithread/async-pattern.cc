//
// Created by lizgao on 1/25/19.
//

#include <glog/logging.h>
#include <functional>
namespace {

// network request/response
void BlockFunction(std::function<void(void)> cb) {



}
class Event {
 public:
  void Do() {}
};
bool has_events(Event **event) {
  return true;
}
void main_loop() {

  Event *event;

  while(has_events(&event)) {
    event->Do();
  }

}

}

