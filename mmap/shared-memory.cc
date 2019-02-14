//
// Created by lizgao on 1/14/19.
//

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <glog/logging.h>

volatile uint64_t sink;

void shared_memory_test() {
  /*
  const char *filename = argv[1];
  int populate = !strcmp(argv[2], "populate");
  uint8_t *memblock;
  int fd;
  struct stat sb;

  fd = open(filename, O_RDONLY);
  fstat(fd, &sb);
  uint64_t size = sb.st_size;

  memblock = mmap(NULL, size, PROT_READ, MAP_SHARED | (populate ? MAP_POPULATE : 0), fd, 0);

  if (memblock == MAP_FAILED) {
    perror("mmap failed");
    return EXIT_FAILURE;
  }

  //printf("Opened %s of size %lu bytes\n", filename, size);

  uint64_t i;
  uint8_t result = 0;
  for (i = 0; i < size; i++) {
    result += memblock[i];
  }

  sink = result;

  puts("Press enter to exit...");
  getchar();

  return EXIT_SUCCESS;
   */
}
