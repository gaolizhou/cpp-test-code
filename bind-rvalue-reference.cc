//
// Created by lizgao on 4/17/18.
//
#include <functional>
#include <iostream>
#include <string>

namespace {
class Widget{
std::string xx;
};


}
void bind_rvalue_reference(){
  Widget w;
  auto lambda_fun = std::bind([](Widget&& ref){ std::cout << "lambda" << std::endl; }, std::move(w));
  //lambda_fun();
  std::cout << "end" << std::endl;
}
