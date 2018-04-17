//
// Created by lizgao on 3/29/18.
//

#include "ThreadPool.h"
#include <iostream>
#include "glog/logging.h"

namespace {
class KLASS {
 public:
  int fun() {
    LOG(INFO) << "Member fun" ;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return 0;
  }

};

}

void thread_pool_test() {
  ThreadPool pool(4);
  std::vector< std::future<int> > results;

  for(int i = 0; i < 8; ++i) {
    results.emplace_back(
        pool.enqueue([i] {
          LOG(INFO) << "hello " << i << std::endl;
          std::this_thread::sleep_for(std::chrono::seconds(1));
          LOG(INFO) << "world " << i << std::endl;
          return i*i;
        })
    );
  }

  KLASS xx;
  results.emplace_back(pool.enqueue(std::bind(&KLASS::fun, std::ref(xx))));

  for(auto && result: results)
    LOG(INFO) << result.get() << ' ';
}