//
// Created by lizgao on 2/6/19.
//
#include <cstdlib>
#include <cstdio>
#include <unistd.h>

void memory_test()  {
  write(1, "memory test 1\n", 14);
  int *a = (int*)malloc(1024*1024*100*4);
  a[0] = 0;

  for (int i = 0; i < 3096; ++i) {
    a[i] = i;
  }


  printf("a address is %p\n", a);
  printf("&a address is %p\n", &a);
  int *b = (int*)malloc(44);
  b[0] = 0;

  printf("b address is %p\n", b);
  printf("&b address is %p\n", &b);
  write(1, "memory test 2\n", 14);

  getchar();
  free(a);
  free(b);
  getchar();
}