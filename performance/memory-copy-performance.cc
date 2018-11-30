//
// Created by lizgao on 11/30/18.
//

#include <glog/logging.h>

constexpr int MEMSIZE = 4096;
constexpr int COPYCNT = 1000000;

void memory_copy_performance() {
  char src[MEMSIZE];
  char dst[MEMSIZE];
  LOG(INFO) << "Start Copying size=" << MEMSIZE << ", cnt=" << COPYCNT;
  for (int i = 0; i < COPYCNT; ++i) {
    memcpy(dst, src, MEMSIZE);
  }
  LOG(INFO) << "Copying done";
}