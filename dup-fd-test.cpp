//
// Created by lizgao on 8/23/18.
//
#include <unistd.h>

void dup_fd_test() {
  int p[2];
  char *argv[2];
  argv[0] = "wc";
  argv[1] = 0;
  pipe(p);
  if(fork() == 0) {
    close(STDIN_FILENO); //CHILD CLOSING stdin
    dup(p[STDIN_FILENO]); // copies the fd of read end of pipe into its fd i.e 0 (STDIN)
    close(p[STDIN_FILENO]);
    close(p[STDOUT_FILENO]);
    execv("/bin/wc", argv);
  } else {
    write(p[STDOUT_FILENO], "hello world\n", 12);
    close(p[STDIN_FILENO]);
    close(p[STDOUT_FILENO]);
  }

}