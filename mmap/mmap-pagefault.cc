//
// Created by lizgao on 12/27/18.
//
#include <sys/mman.h>
#include <glog/logging.h>
#include <iostream>

void mmap_pagefault() {
  //MAP_POPULATE
  auto region = mmap(NULL, 4096*4000, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  if (region == MAP_FAILED) {
    LOG(ERROR) << "Failed to mmap " << strerror(errno);
    region = nullptr;
    return;
  }

  LOG(INFO) << "mmap sucessfully!";
  int x;
  std::cin >> x;

  LOG(INFO) << "start touching!";

  /*for (int i = 0; i < 4000; ++i) {
    ((char*)region)[4096*i] = 1;
    ((char*)region)[4096*i+512] = 1;
  }*/
  for (int i = 0; i < 4000 * 4096; ++i) {
    ((char*)region)[i] = 1;
  }

  LOG(INFO) << "end touching!";

  while(true) {
    sleep(1);
  }
}