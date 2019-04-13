//
// Created by lizgao on 5/10/18.
//
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <glog/logging.h>
#include <fcntl.h>
#include <sys/mman.h>

namespace {
void sig_chld( int signo ) {
  pid_t pid;
  int stat;
  pid = wait(&stat);
  LOG(INFO) << "child "<< pid << " exit";
}

}
void zombie_process() {
 // signal(SIGCHLD,  &sig_chld);
  constexpr int LEN = 400*1024;

  pid_t child = fork();
  int fd = open("1.txt", O_RDWR|O_CREAT);
  if(fd < 0) {
    LOG(ERROR) << "Cannot open 1.txt";
    return;
  }

  auto region = mmap(NULL, LEN, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (region == MAP_FAILED) {
    LOG(ERROR) << "Failed to mmap " << strerror(errno);
    region = nullptr;
    return;
  }
  for (int i = LEN-1; i >=0; i--) {
    ((char*)region)[i] = 0x31;
  }
  LOG(INFO) << "Write is done ";

  if( child < 0  ) {     //fork error.
    LOG(INFO) << "fork process fail.";
  } else if( child ==0  ) {   // in child process
    LOG(INFO) << "fork succ, this run in child process";
    sleep(6000);
  } else {                        // in parent process
    LOG(INFO) << " this run in parent process";
    sleep(6000);
  }
}