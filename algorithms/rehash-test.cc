//
// Created by lizgao on 1/7/19.
//

#include <glog/logging.h>
#include <functional>
#include <vector>
#include <string>

namespace {

struct Node {
  Node *next;
  int key;
  std::string value;
};

class MyHashTable {
 public:
  MyHashTable() {
    mask_ = ((~0) >> bucket_number_) << bucket_number_;
    mask_ = ~mask_;
    bucket_ = new Node*[1ULL << bucket_number_];
    memset(bucket_, 0, (1ULL << bucket_number_)*sizeof(Node*));
  }
  ~MyHashTable() {
    for (int i = 0; i < (1ULL << bucket_number_); i++) {
      auto ptr = bucket_[i];
      while (ptr) {
        auto tmp = ptr->next;
        free(ptr);
        ptr = tmp;
      }
    }
    free(bucket_);
  }

  void ReHash() {

  }

  std::string &operator[](int key) {
    auto h = std::hash<int>()(key) & mask_;
    //LOG(INFO) << "Bucket=" << h;
    Node **b = &bucket_[h];
    while (*b) {
      if ((*b)->key == key) {
        return (*b)->value;
      }
      b = &((*b)->next);
    }
    *b = new Node(Node{nullptr, key, ""});
    return (*b)->value;
  };

  void Dump() {

  }

 private:
  int bucket_number_ = 10;
  uint64_t mask_;
  Node **bucket_;
};

}

void rehash_test() {
  MyHashTable table;
  table[100]="Hello World!-1";
  table[1000]="Hello World!-2";
  table[10000]="Hello World!-3";
  table[100+1024]="Hello World!-1+1024";
  table[1000+1024]="Hello World!-2+1024";
  table[10000+1024]="Hello World!-3+1024";
  LOG(INFO) << table[100];
  LOG(INFO) << table[1000];
  LOG(INFO) << table[10000];
  LOG(INFO) << table[100+1024];
  LOG(INFO) << table[1000+1024];
  LOG(INFO) << table[10000+1024];
}