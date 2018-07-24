//
// Created by lizgao on 7/13/18.
//
#include <cstdint>
#include <thread>
#include <atomic>
#include <glog/logging.h>

namespace {
struct GConf
{
  int64_t a;
  int64_t b;
  int64_t c;
};
GConf g_conf = {
    1,1,1
};
bool stop = false;
std::atomic_int lock = {0};

void ReadThreadFun() {
  while(!stop) {
    while(lock == -1);
    lock.fetch_add(1);
    GConf local_conf = g_conf;
    lock.fetch_add(-1);
    if (local_conf.a == local_conf.b && local_conf.a == local_conf.c) {
      continue;
    }
    LOG(INFO) << "a="<<local_conf.a << ",b="<<local_conf.b << ",c="<< local_conf.c;
    stop = true;
  }
}

void WriteThreadFun() {
  while(!stop) {
    while(lock != 0);
    lock = -1;
    ++g_conf.a;
    ++g_conf.b;
    ++g_conf.c;
  }
}

}

void atomic_op_test() {
  std::thread tid_read = std::thread(&ReadThreadFun);
  std::thread tid_write = std::thread(&WriteThreadFun);

  tid_read.join();
  tid_write.join();
}
