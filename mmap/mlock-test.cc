//
// Created by lizgao on 1/13/19.
//

#include <sys/mman.h>
#include <glog/logging.h>
#include <iostream>

void mlock_pagefault() {
  //MAP_POPULATE
  auto region = mmap(NULL, 400*1024*1024, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  if (region == MAP_FAILED) {
    LOG(ERROR) << "Failed to mmap " << strerror(errno);
    region = nullptr;
    return;
  }

  LOG(INFO) << "mmap sucessfully!";
  int x;
  std::cin >> x;

  LOG(INFO) << "start mlock!";

  mlock(region, 400*1024*1024);

  LOG(INFO) << "end mlock!";

  while(true) {
    sleep(1);
  }
}