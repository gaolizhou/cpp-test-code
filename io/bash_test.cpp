//
// Created by lizgao on 10/27/18.
//

#include <glog/logging.h>
#include <string>
#include <fcntl.h>

void bash_test() {
  auto fd = dup(STDOUT_FILENO);
  LOG(INFO) << "after dup=" << fd;
  std::string str =  "HELLO  WORLD!\n";
  write(fd, str.c_str(), str.size());
  int file_fd = open("1.txt", O_WRONLY|O_CREAT|O_TRUNC);
  auto ret = dup2(file_fd, STDOUT_FILENO);
  auto ret2 = dup2(file_fd, STDERR_FILENO);
  LOG(INFO) << "after dup2=" << file_fd << ",ret=" << ret;
  write(STDOUT_FILENO, str.c_str(), str.size());
  close(file_fd);
}
