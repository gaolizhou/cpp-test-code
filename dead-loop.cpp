//
// Created by lizgao on 9/30/18.
//
#include <map>
#include <glog/logging.h>

void dead_loop_test() {
  std::map<int, int> inflying_list_;
  inflying_list_[1]=1;
  for (auto item = inflying_list_.begin(); item != inflying_list_.end(); ) {
    if (item->first == 12) {
      LOG(INFO) << "OpTimeout. op_seq=" << item->first << ", lc_id=";
        item = inflying_list_.erase(item);
    } else {
      ++item;
    }
  }
  LOG(INFO) <<  "End";
}