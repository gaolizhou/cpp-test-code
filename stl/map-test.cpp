//
// Created by lizgao on 10/31/18.
//

#include <stdio.h>

#include <map>
#include <string>

void map_test() {
  std::map<std::string, std::string> x;
  int i = 0x5001;
  x["foo"] = i;

  printf("%s", x["foo"].c_str());
}