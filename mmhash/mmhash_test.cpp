//
// Created by lizgao on 11/6/18.
//


#include "murmur_hash2.h"
#include <glog/logging.h>

void mmhash_test() {

  std::string key = "abcdefg";
  LOG(INFO) << "hash = " << MurmurHash2(key.c_str(), key.size(), 0);
  LOG(INFO) << "hash = " << MurmurHash64A(key.c_str(), key.size(), 0);
  LOG(INFO) << "hash = " << MurmurHash64B(key.c_str(), key.size(), 0);

}