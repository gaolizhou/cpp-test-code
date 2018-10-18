//
// Created by lizgao on 9/25/18.
//

#include <memory>
#include <glog/logging.h>
namespace {
struct Data {
  int x1;
  int x2;
  int x3;
  int x4;
};
}
void shared_ptr_size() {
  auto p1 = std::make_shared<int>(10);
  auto p2 = std::shared_ptr<int>(new int(10));
  auto p3 = std::make_shared<Data>();
  auto p4 = std::shared_ptr<Data>(new Data);
  auto data = new Data;
  data->x1 = 1;
  data->x2 = 2;
  data->x3 = 3;
  data->x4 = 4;
  LOG(INFO) << "&data = " << data;
  auto p5 = std::shared_ptr<Data>(data);
  LOG(INFO) << "&p5 = " << &p5;
  LOG(INFO) << sizeof(p1);
  LOG(INFO) << sizeof(p2);
  LOG(INFO) << sizeof(p3);
  LOG(INFO) << sizeof(p4);
}
