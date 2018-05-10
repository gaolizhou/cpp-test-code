//
// Created by lizgao on 5/3/18.
//
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <glog/logging.h>

namespace {
struct Data {
 private:
  std::string s_;
 public:
  static int cnt;
  Data(std::string &&s) : s_(s) { ++cnt;}
  ~Data() { --cnt; }
};
int Data::cnt = 0;
}


void memory_leak_test2() {
  void *p0 = sbrk(0);

  {
    LOG(INFO) << "BEGIN";
    const size_t CNT = 5000000;
    std::vector<std::shared_ptr<std::string>> data;

    data.reserve(CNT);

    for (int i = 0; i < CNT; ++i) {
      data.push_back(std::make_shared<std::string>(std::to_string(i)));
    }
    LOG(INFO) << "Finish";
    for (int i = 0; i < CNT; ++i) {
      data[i].reset();
    }
  }
  //sbrk(-200*1024*1024);
  void *p = sbrk(0);
  std::cout << std::hex << p<<std::endl;
  int diff = (char*)p0 - (char*)p;
  std::cout << std::dec << diff <<std::endl;
  sbrk(diff);
  std::cin.get();

}


void memory_leak_test1() {
  std::cin.get();
  {
    LOG(INFO) << "BEGIN";
    const size_t CNT = 5000000;
    std::vector<std::shared_ptr<Data>> data;

    data.reserve(CNT);

    for (int i = 0; i < CNT; ++i) {
      data.push_back(std::make_shared<Data>(std::to_string(i)));
    }
    LOG(INFO) << "Finish cnt=" << Data::cnt;


    std::cin.get();
    for (int i = 0; i < CNT; ++i) {
      data[i].reset();
    }
  }

  LOG(INFO) << "cnt = " << Data::cnt;
  std::cin.get();
}


void memory_leak_test() {
  std::cin.get();
  const size_t CNT = 50000000;
  for (int j = 0; j < 30; ++j) {
    LOG(INFO) << "BEGIN";
    std::vector<Data> data;
    size_t cnt = CNT + rand()%1000;
    data.reserve(cnt);
    for (int i = 0; i < cnt; ++i) {
      data.emplace_back(Data(std::to_string(i)));
    }
    LOG(INFO) << "Finish cnt=" << Data::cnt;

    //std::cin.get();
    //for (int i = 0; i < CNT; ++i) {
    //  data[i].reset();
    //}
  }

  LOG(INFO) << "cnt = " << Data::cnt;
  std::cin.get();
}
