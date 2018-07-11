//
// Created by lizgao on 7/9/18.
//

namespace {

struct Node {
  Node *next;
  void *data;
};

struct List {
  Node *head;
  Node *tail;
  void push_back(void *ptr) {

    Node *new_node = new Node();
    new_node->next = nullptr;
    new_node->data = ptr;
    if (tail) {
      tail->next = new_node;
    } else {
      head = new_node;
    }
    tail = new_node;
  }
  void* pop_front() {
    if(!head) {
      return nullptr;
    }
    auto data = head->data;
    head = head->next;
    return data;
  }
};



}

void lock_free_link_list() {

}