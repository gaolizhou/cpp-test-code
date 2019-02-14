//
// Created by lizgao on 1/17/19.
//
#include <iostream>
using namespace std;
namespace {
class Base {
 public:
  Base() {

  }
 private:
  int x_;
};

class Derive : public Base {
 public:
  Derive() = default;
  virtual ~Derive() = default;
  void fun() {
    cout << "fun" << endl;
  }
 private:
  int y_;
};

Base *MakeObject() {
  Derive *d = new Derive();
  cout << "addr of d = " << d << endl;
  return d;
}

}

void static_cast_test2() {
  auto b = MakeObject();
  cout << "addr of b = " << b << endl;
}