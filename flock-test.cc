//
// Created by lizgao on 2/19/19.
//

#include <fcntl.h>
#include <sys/file.h>
#include <glog/logging.h>

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
  int fdlist[4096];
  for (int i=0;i<4096;i++) {
    //fdlist[i] = open(lock_file, O_CREAT | O_RDWR, 0600);
  }
  LOG(INFO) << "Sucessfully in flock " << lock_file << ", now sleep 10 seconds";
  sleep(10);
  LOG(INFO) << "Now Finish";
  close(fd);
}