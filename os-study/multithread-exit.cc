//
// Created by lizgao on 3/4/19.
//
#include <glog/logging.h>
#include <pthread.h>
#include <iostream>
namespace {
void* thread_fun(void* arg) {

  int id = *reinterpret_cast<int*>(arg);

  std::cout << "my id = " << id << std::endl;

  sleep(100);
  return nullptr;
}
}

void multithread_exit_test() {

  pthread_t tid[5];
  for (int i = 0; i < 5; ++i) {
    tid[i] = pthread_create(&tid[i], nullptr, &thread_fun, &i);
  }

  pthread_exit(nullptr);
}