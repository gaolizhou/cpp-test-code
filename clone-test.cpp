//
// Created by lizgao on 8/29/18.
//
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

namespace {
static char child_stack[1048576];

static int child_fn(void*) {
  printf("PID: %ld\n", (long) getpid());
  return 0;
}
}
void clone_test() {
  pid_t child_pid = clone(child_fn, child_stack+1048576, CLONE_NEWPID | SIGCHLD, NULL);
  printf("clone() = %ld\n", (long)child_pid);

  waitpid(child_pid, NULL, 0);
}
