//
// Created by lizgao on 2/19/19.
//

#include <fcntl.h>
#include <sys/file.h>
#include <glog/logging.h>
#include <sys/mman.h>

namespace {
int resize_and_map(int fd, void *addr, size_t len)
{
  void *map_addr;

  if (ftruncate(fd, len)) {
    LOG(ERROR) << "Cannot truncate";
    return -1;
  }

  map_addr = mmap(addr, len, PROT_READ | PROT_WRITE,
                  MAP_SHARED | MAP_FIXED, fd, 0);
  if (map_addr != addr) {
    LOG(ERROR) << "mmap() failed: " << strerror(errno);
    return -1;
  }
  return 0;
}

}

void flock_test() {
  char *lock_file = "flock-test.lock";
  int fd = open(lock_file, O_CREAT | O_RDWR, 0600);
  if(fd < 0) {
    LOG(ERROR) << "Error in opening " << lock_file;
    return;
  } else if (flock(fd, LOCK_EX | LOCK_NB)) {
    LOG(ERROR) << "Error in flock " << lock_file;
    system("lsof flock-test.lock");
    close(fd);
    return;
  }
  if (flock(fd, LOCK_SH | LOCK_NB)) {
    LOG(ERROR) << "Error in flock LOCK_SH " << lock_file;
    close(fd);
    return;
  }
  char data[100];
  resize_and_map(fd, data, 100);
  close(fd);
  LOG(INFO) << "Sucessfully in flock " << lock_file << ", now sleep 10 seconds";
  sleep(10);
  LOG(INFO) << "Now Finish";
}