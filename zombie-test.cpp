//
// Created by lizgao on 7/8/18.
//

#include <glog/logging.h>

void zombie_test() {

  auto pid = fork();
  LOG(INFO) << "pid = " << pid;
  if (pid == 0) {
    LOG(INFO) << "I am children!";
  } else{
    LOG(INFO) << "I am parent!";
    sleep(10);
    LOG(INFO) << "parent finish!";
  };
}

