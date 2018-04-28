//
// Created by lizgao on 4/28/18.
//

#include <iostream>
#include <string>
using namespace std;

namespace {
// Some function X.
// It takes an rvalue ref to s, but doesn't move data out of it.
// It promises to return "true", if it ever moves out of "s".
bool X(string &&s) {
  s.pop_back();
  return false;
}

// Some function Y.
// It moves out of "s" and then dumps garbage into it.
// Because it can.
void Y(string &&s) {
  string local_string = std::move(s);

  s = "Muahaha! Garbage!";
}
}
void move_string_test()
{
  string s("Hello, world!");
  string&& rvalue_ref_to_s = std::move(s);

  cout << "1. std::move by itself doesn't change the string:" << endl;
  cout << s << endl; // prints "Hello, world!"

  bool wasMoved = X(std::move(s));
  if (!wasMoved)
  {
    cout << "2. We know that data wasn't moved out of ""s""," << endl;
    cout << "   because such is the contract of X(...)," << endl;
    cout << "   we can continue working with ""s"" as usual" << endl;
    cout << s << endl; // prints "Hello, world"
  }

  Y(std::move(s));
  cout << s << endl; // prints "Hello, world"

  // 3. Data was moved out of "s", but it is not empty.
  // If we want to continue using "s", we should reset it,
  // or assign something to it.
  s = "The New World";


  string s2(std::move(s));

  // 4. You might think that now "s" is definitely empty,
  // but the standard only promises that "s" is in a
  // "valid but unspecified" state, so you should only call
  // methods without preconditions to remain within
  // the bounds of the specified behavior.
  s.clear();
}