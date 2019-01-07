//
// Created by lizgao on 12/31/18.
//

#include <atomic>
#include <glog/logging.h>
#include <iostream>
#include <thread>
namespace {

struct Node {
  int val;
  Node *next;
};

class LockFreeStack {
 public:
  void push(int value) {

    Node * node = new Node {value, nullptr};

    Node *old_head_  = head_.load(std::memory_order::memory_order_relaxed);
    do {
      node->next = old_head_;
    } while (!head_.compare_exchange_weak(old_head_, node, std::memory_order::memory_order_release, std::memory_order::memory_order_relaxed));
  }

  bool pop(int *value) {
    Node *next;
    Node *old_head_ = head_.load(std::memory_order::memory_order_relaxed);
    do {
      if(!old_head_) {
        return false;
      }
      next = old_head_->next;
    } while (!head_.compare_exchange_weak(old_head_, next, std::memory_order::memory_order_relaxed));

    if (old_head_) {
      *value = old_head_->val;
      free(old_head_);
      return true;
    }
    return false;
  }

  void dump() {
    Node *tmp = head_;
    while(tmp) {
      std::cout << tmp->val << "\n";
      tmp = tmp->next;
    }
  }
  void dump2() {
    int val;
    while(pop(&val)) {
      std::cout << val << ",";
    }
  }

 private:
  std::atomic<Node*> head_ = { nullptr };
};

LockFreeStack stack;
}

void lockfree_stack_test() {
  auto f = []() {
    for (int i = 0; i < 100000; ++i) {
      stack.push(i);
    }
  };
  std::thread tid1(f);
  std::thread tid2(f);
  std::thread tid3(f);
  std::thread tid4(f);
  tid1.join();
  tid2.join();
  tid3.join();
  tid4.join();
  stack.dump2();
}

