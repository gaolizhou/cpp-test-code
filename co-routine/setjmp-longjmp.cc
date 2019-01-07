//
// Created by lizgao on 1/7/19.
//

#include <setjmp.h>
#include <stdio.h>
#include <glog/logging.h>

namespace {

void fancy_func(jmp_buf env) {
  puts("doing fancy stuff");
  longjmp(env, 1);
}

}

void jmp_test() {
  jmp_buf env;
  int ret = setjmp(env);
  if (ret == 0) {
    LOG(INFO) << "just returning from setjmp!";
    fancy_func(env);
  } else {
    LOG(INFO) << "now returning from longjmp and exiting!";
  }
}
