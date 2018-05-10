//
// Created by lizgao on 5/10/18.
//
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <glog/logging.h>

namespace {
void sig_chld( int signo ) {
  pid_t pid;
  int stat;
  pid = wait(&stat);
  LOG(INFO) << "child "<< pid << " exit";
}

}
void zombie_process() {
  signal(SIGCHLD,  &sig_chld);

  pid_t child = fork();
  if( child < 0  ) {     //fork error.
    LOG(INFO) << "fork process fail.";
  } else if( child ==0  ) {   // in child process
    LOG(INFO) << "fork succ, this run in child process";
  } else {                        // in parent process
    LOG(INFO) << " this run in parent process";
    sleep(600);
  }
}