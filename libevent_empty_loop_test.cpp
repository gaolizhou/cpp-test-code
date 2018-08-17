//
// Created by lizgao on 8/15/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <event.h>
#include <event2/event.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <glog/logging.h>

namespace {
class SocketClient {
 public:
  SocketClient() {
    base_ = event_base_new();
   // ev_ = event_new(base_, -1, EV_PERSIST, &SocketClient::cb_func, event_self_cbarg());
   // struct timeval one_sec = { 1, 0 };
   // event_add(ev_, &one_sec);
  }
  ~SocketClient() {
    event_base_free(base_);
  }
  static void cb_func(evutil_socket_t fd, short what, void *arg) {
    static int n_calls = 0;

    printf("cb_func called times so far %d.\n", ++n_calls);

    if (n_calls < 10) {
      struct timeval tv_1 = {1,0};
      struct event *event_timeout_1 = evtimer_new((struct event_base *)arg, &SocketClient::cb_func, arg);
      event_add(event_timeout_1,&tv_1);

    }
  }
 public:
  void Start() {
    struct timeval tv;

    tv.tv_sec = 1;
    tv.tv_usec = 0;

    ev_ = evtimer_new(base_, &SocketClient::cb_func, base_);
    event_add(ev_,&tv);

    event_base_dispatch(base_);
    //EVLOOP_NO_EXIT_ON_EMPTY
    //event_base_loop(base_, EVLOOP_NO_EXIT_ON_EMPTY);
  }
  void Stop() {
  }
 private:
  struct event_base *base_;
  struct event *ev_;
};

}

void bufferevent_empty_loop_test() {
  LOG(INFO) << "BEGIN";
  SocketClient().Start();
  LOG(INFO) << "END";
}