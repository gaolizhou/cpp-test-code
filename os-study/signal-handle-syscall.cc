//
// Created by lizgao on 2/25/19.
//

#include <glog/logging.h>

void signal_handle_no_syscall() {
  int sum = 0;
  while(true) {
    for(int i=0;i<1000;i++) {
      sum += i;
    }
  }
  LOG(INFO) << "sum = " << sum;
}