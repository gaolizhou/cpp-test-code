//
// Created by lizgao on 11/8/18.
//
#include <glog/logging.h>
#include <fcntl.h>

void unlink_test() {

  int fd = open("lock.txt", O_RDWR | O_CREAT);
  LOG(INFO) << "Open fd="<< fd;
  LOG(INFO) << "write1 ret="<< write(fd, "abcd", 4);
  unlink("lock.txt");
  LOG(INFO) << "write2 ret="<< write(fd, "abcd", 4);
  sleep(5);
  LOG(INFO) << "write3 ret="<< write(fd, "abcd", 4);
  close(fd);
}