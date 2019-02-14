//
// Created by lizgao on 2/6/19.
//

#include <iostream>
#include <queue>
#include <map>

using namespace std;

class os {
 public:
  void sleep(int f, void (*h)()) {}

  void wake(int f) {
    auto iter = sleeping.find(f);
    if(iter != sleeping.end()) {
      queue<void (*)()> q = iter->second;
      while(!q.empty()) {
        running.push(q.front());
        q.pop();
      }
    }
  }
 private:
  queue<void (*)()> running;
  map<int, queue<void (*)()>> sleeping;
};