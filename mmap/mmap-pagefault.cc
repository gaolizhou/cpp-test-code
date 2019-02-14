//
// Created by lizgao on 12/27/18.
//
#include <sys/mman.h>
#include <glog/logging.h>
#include <iostream>
//different results with below two CLIs
//ps -o min_flt,maj_flt `pgrep cmake`
//perf stat ./cmake
constexpr int LEN = 4000*4096;
void mmap_pagefault() {
  //MAP_POPULATE
  auto region = mmap(NULL, LEN, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_POPULATE, -1, 0);
  if (region == MAP_FAILED) {
    LOG(ERROR) << "Failed to mmap " << strerror(errno);
    region = nullptr;
    return;
  }
  madvise(region, LEN, MADV_SEQUENTIAL);
  LOG(INFO) << "mmap sucessfully!";
  int x;
  std::cin >> x;

  LOG(INFO) << "start touching!";

  /*for (int i = 0; i < 4000; ++i) {
    ((char*)region)[4096*i] = 1;
    ((char*)region)[4096*i+512] = 1;
  }*/
  /*
  for (int i = 0; i < LEN; ++i) {
    ((char*)region)[i] = 1;
  }*/
  for (int i = LEN-1; i >=0; i--) {
    ((char*)region)[i] = 1;
  }

  LOG(INFO) << "end touching!";
/*
  while(true) {
    sleep(1);
  }*/
}