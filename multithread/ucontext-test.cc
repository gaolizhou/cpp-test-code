//
// Created by lizgao on 1/26/19.
//

#include <stdio.h>
#include <ucontext.h>
#include <glog/logging.h>
namespace {
static ucontext_t ctx[3];

static void func1(void) {
  LOG(INFO) << "fun1 before swapcontext";
  // 切换到func2
  swapcontext(&ctx[1], &ctx[2]);

  LOG(INFO) << "fun1 after swapcontext";
  // 返回后，切换到ctx[1].uc_link，也就是main的swapcontext返回处
}
static void func2(void) {
  LOG(INFO) << "fun2 before swapcontext";
  // 切换到func1
  swapcontext(&ctx[2], &ctx[1]);
  LOG(INFO) << "fun2 after swapcontext";

  // 返回后，切换到ctx[2].uc_link，也就是func1的swapcontext返回处
}
}
void ucontext_test (void)
{
  // 初始化context1，绑定函数func1和堆栈stack1
  char stack1[8192];
  getcontext(&ctx[1]);
  ctx[1].uc_stack.ss_sp   = stack1;
  ctx[1].uc_stack.ss_size = sizeof(stack1);
  ctx[1].uc_link = &ctx[0];
  makecontext(&ctx[1], func1, 0);

  // 初始化context2，绑定函数func2和堆栈stack2
  char stack2[8192];
  getcontext(&ctx[2]);
  ctx[2].uc_stack.ss_sp   = stack2;
  ctx[2].uc_stack.ss_size = sizeof(stack1);
  ctx[2].uc_link = &ctx[1];
  makecontext(&ctx[2], func2, 0);

  // 保存当前context，然后切换到context2上去，也就是func2
  swapcontext(&ctx[0], &ctx[2]);
}