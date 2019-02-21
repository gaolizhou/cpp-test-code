//
// Created by lizgao on 2/17/19.
//
#include <algorithm>
#include <vector>
#include <glog/logging.h>

namespace {
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
}


void remove_if_test() {
  std::vector<ListNode*> pending_node_list(1);
  pending_node_list.erase(std::remove_if(pending_node_list.begin(), pending_node_list.end(),
                 [](ListNode* node){ return !node; }),pending_node_list.end());
  LOG(INFO) << "pending_node_list.empty=" << pending_node_list.empty();
  LOG(INFO) << "pending_node_list.size=" << pending_node_list.size();
}
