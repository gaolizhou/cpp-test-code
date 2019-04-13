//
// Created by lizgao on 3/3/19.
//

#include<glog/logging.h>
#include<thread>

using namespace std;
namespace {
  void threadA (int id) {
    int a = 0;
    LOG(INFO) << "thread " << id << " stack is " << &a;

    int c = 0;

    int * b = (int *) malloc(4);

    LOG(INFO) << "thread " << id  << " heap is " << b;
    free(b);
    sleep(100);
  }

}

void testStack() {

  int a = 0;
  LOG(INFO) << __FUNCTION__ << " stack is " << &a;

  int * b = (int *) malloc(4);

  LOG(INFO) << __FUNCTION__ << " heap is " << b;
  free(b);


  thread t[5];
  for (int i = 0; i < 5; ++i) {
    t[i] = thread(threadA, i);

  }

//  for (auto& th: t) {
//    th.join();
//  }



}