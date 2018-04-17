//
// Created by lizgao on 4/4/18.
//

#include <sstream>
#include <string>
#include <iterator>
#include "glog/logging.h"

namespace {
std::string Binary2String(const uint8_t *ptr, int64_t len) {
  std::ostringstream oss;
  oss << std::hex;
  std::copy(ptr, ptr+len, std::ostream_iterator<int>(oss, " "));
  return oss.str();
}

}

void Binary2StringTest() {
  uint8_t data[5] = {0x11, 0x22, 0x33, 0x44, 0x55};
  LOG(INFO) << Binary2String(data, 5);
}