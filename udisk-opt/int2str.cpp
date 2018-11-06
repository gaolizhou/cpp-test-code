//
// Created by lizgao on 11/6/18.
//
#include <cstdint>
#include <cstdlib>
#include <memory.h>
#include <glog/logging.h>

namespace {
const char digit_pairs[201] = {
    "00010203040506070809"
    "10111213141516171819"
    "20212223242526272829"
    "30313233343536373839"
    "40414243444546474849"
    "50515253545556575859"
    "60616263646566676869"
    "70717273747576777879"
    "80818283848586878889"
    "90919293949596979899"
};

static const int BUFFER_SIZE = 11;

unsigned int itostr(unsigned int val, char *result)
{
  char buf[BUFFER_SIZE];
  char *it = (char*)&buf[BUFFER_SIZE-2];

  int div = val/100;
  while(div) {
    memcpy(it,&digit_pairs[2*(val-div*100)],2);
    val = div;
    it-=2;
    div = val/100;
  }
  memcpy(it,&digit_pairs[2*val],2);
  if(val<10)
    it++;

  unsigned int len = (char*)&buf[BUFFER_SIZE]-(char*)it;
  memcpy(result, it, len);
  return len;
}
}


void int2str_test() {
  uint32_t lcid = 0;
  uint32_t pc = 10;
  uint32_t lcrandomid = 123456;
  char key[128];
  memset(key, 0, 128);

  auto len = itostr(lcid, key);
  key[len++] = '-';
  len += itostr(pc, &key[len]);
  key[len++] = '-';
  itostr(lcrandomid, &key[len]);
  LOG(INFO) << "key="<<key;
}