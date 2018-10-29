//
// Created by lizgao on 10/29/18.
//
#include <unistd.h>
#include <glog/logging.h>
#include <sys/wait.h>

void pipe_test() {
  int pipefd[2] = {0,0};
  auto ret = pipe(pipefd);
  LOG(INFO) << "fd="<<pipefd[0] << ", " << pipefd[1] << ", ret=" << ret;

  auto child_pid = fork();
  if(child_pid != 0) {
    close(pipefd[0]);
    LOG(INFO) << "parent pid=" << getpid() << ",ppid=" << getppid() << ", child pid=" << child_pid;
    std::string msg1("HELLO WORLD! -- 1");
    std::string msg2("HELLO WORLD! -- 2");
    write(pipefd[1], msg1.c_str(), msg1.size());
    write(pipefd[1], msg2.c_str(), msg2.size());
    close((pipefd[1]));
    int status = 0;
    auto wpid = wait(&status);
    LOG(INFO) << "child end! "<< "wpid=" << wpid << ", status=" << WEXITSTATUS(status);
  } else {
    close(pipefd[1]);
    char buff[1024] = {0};
    usleep(1000*1000);
    auto ret = read(pipefd[0], buff, 1024);
    LOG(INFO) << buff << ", ret="<<ret;
    ret = read(pipefd[0], buff, 1024);
    LOG(INFO) << buff << ", ret="<<ret;
    LOG(INFO) << "child pid=" << getpid() << ",ppid=" << getppid();
    close(pipefd[0]);
    exit(4);
  }
}