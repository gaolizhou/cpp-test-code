//
// Created by lizgao on 5/4/18.
//

#include <sys/mman.h>
#include <unistd.h>
#include <stdint.h>
#include <glog/logging.h>
#include <iostream>

void shr_mem_test()
{
  /* mmap 50MiB of shared anonymous memory */
  char *p = reinterpret_cast<char*>(mmap(NULL, 50 << 20, PROT_READ | PROT_WRITE,
                 MAP_ANONYMOUS | MAP_SHARED, -1, 0));

  /* Touch every single page to make them resident */
  for (int i = 0; i < (50 << 20) / 4096; i++) {
    p[i * 4096] = 1;
  }
  LOG(INFO) << "shr_mem_test end";
  std::cin.get();
}
