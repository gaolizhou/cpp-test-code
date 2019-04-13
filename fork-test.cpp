//
// Created by lizgao on 9/14/18.
//

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <glog/logging.h>
#include <fcntl.h>
#include <sys/mman.h>

void fork_test(void)
{
   char parent_str[] = "parent write!\n";
   char child_str[] = "child write!\n";
   int fd = open("fork_write.txt", O_RDWR|O_CREAT);
   if(fd < 0) {
      LOG(ERROR) << "Cannot open 1.txt";
      return;
   }

   pid_t child = fork();
   if(child > 0) {
      write(fd, parent_str, strlen(parent_str));
      sleep(6000);
      close(fd);
      wait(NULL);
   } else {
      write(fd, child_str, strlen(child_str));
      sleep(6000);
      close(fd);
   }


}