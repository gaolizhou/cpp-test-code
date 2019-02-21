//
// Created by lizgao on 2/18/19.
//

#include <glog/logging.h>

namespace {

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
 public:
  ListNode *partition(ListNode *head, int x) {
    if(!head) {
      return head;
    }
    auto p = head;
    ListNode* left_head = nullptr;
    ListNode* right_head = nullptr;
    ListNode* left = nullptr;
    ListNode* right = nullptr;
    while(p) {
      if (p->val < x) {
        if(left_head) {
          left->next = p;
          left = p;
        } else {
          left_head = p;
          left = left_head;
        }
      } else {
        if(right_head) {
          right->next = p;
          right = p;
        } else {
          right_head = p;
          right = right_head;
        }
      }
      p = p->next;
    }

    if(right_head) {
      right->next = nullptr;
    }
    if(left_head) {
      left->next = right_head;
    } else {
      left_head = right_head;
    }

    return left_head;

  }
};

}

void partition_test() {

  ListNode *head = new ListNode(1);
  ((((head->next = new ListNode(4))
       ->next =  new ListNode(3))
        ->next =  new ListNode(2))
       ->next =  new ListNode(5))
      ->next =  new ListNode(2);


  Solution().partition(head, 3);

  auto p = head;
  while(p) {
    LOG(INFO) << p->val;
    p = p->next;
  }

}