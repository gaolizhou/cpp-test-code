//
// Created by lizgao on 11/12/18.
//
#include<signal.h>
#include<unistd.h>
#include <glog/logging.h>

namespace {

void sig_handler(int signo) {
  LOG(INFO) << "Enter sig_handler";
  sleep(10);
  if (signo == SIGINT) {
    LOG(INFO) << "received SIGINT";
  }
  LOG(INFO) << "Leave sig_handler";
}

}
void signal_handle_context_test()
{
  if (signal(SIGINT, sig_handler) == SIG_ERR) {
    LOG(ERROR) << "Can't catch SIGINT";
  }
  // A long long wait so that we can easily issue a signal to this process
  while(1) {
    sleep(1);
    LOG(INFO) << "Tick";
  }
}
