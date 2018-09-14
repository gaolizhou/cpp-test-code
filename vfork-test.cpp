//
// Created by lizgao on 9/14/18.
//
#include <unistd.h>
#include <glog/logging.h>
#include <wait.h>

void vfork_test() {
  LOG(INFO) << "before vfork";
  auto pid = vfork();
  if (pid == 0) {
    char *const argvv[] = {"sleep","2",NULL};
    usleep(1000*1000);
    LOG(INFO) << "child process";
    execve("/bin/sleep",argvv,NULL);
  } else {
    LOG(INFO) << "parent process!";
  }
  LOG(INFO) << "before waitpid";
  wait(nullptr);
  LOG(INFO) << "after waitpid";
}
