//
// Created by lizgao on 10/24/18.
//

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <glog/logging.h>
#include <sys/mman.h>

void direct_io_test() {
  const char *fp= "direct_io.txt";
  int flag = O_RDWR | O_CREAT | O_APPEND;
  flag |= O_DIRECT;
  mode_t mode = 0644;

  int fd = open(fp, flag, mode);
  if (fd == -1) {
    LOG(ERROR) << "Failed to open file. Error: " << strerror(errno);
    return;
  }

  LOG(INFO) << "Succeed to open file, file descriptor: " << fd;

  char* buff_align = (char*)mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  memset(buff_align, 0, 4096);
  memcpy(buff_align, "hello\n", 6);
  LOG(INFO) << "buff=" << buff_align;
  auto ret = write(fd, buff_align+512, 512);
  LOG(INFO) << "ret = " << ret;
  if(ret < 0) {
    LOG(ERROR) << "Write Error " << strerror(errno);
  }
  close(fd);
  munmap(buff_align, 4096);
}


