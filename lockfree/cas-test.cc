//
// Created by lizgao on 12/31/18.
//

#include <atomic>
#include <glog/logging.h>

void cas_test() {
  std::atomic<int> value {40};
  int m=8;
  int n=4;
  bool ret1 = value.compare_exchange_weak(n, m);

  LOG(INFO) << "m=" << m << ",n=" << n << ", ret=" << ret1;

  bool ret2 = value.compare_exchange_weak(n, m);

  LOG(INFO) << "m=" << m << ",n=" << n << ", ret=" << ret2;
  ;

  LOG(INFO) << "value="<< value.load() << ",ret1=" << ret1 << ",ret2="<<ret2;
}