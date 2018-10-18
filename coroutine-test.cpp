//
// Created by lizgao on 9/26/18.
//
#include <csetjmp>
#include <cstdio>
#include <cstdlib>
namespace {
static void *coarg;

void *coto(jmp_buf here, jmp_buf there, void *arg) {
  coarg = arg;
  if (setjmp(here)) return (coarg);
  longjmp(there, 1);
}

#define STACKDIR - // set to + for upwards and - for downwards
#define STACKSIZE (1<<12)

static char *tos; // top of stack

void *cogo(jmp_buf here, void (*fun)(void *), void *arg) {
  if (tos == NULL) tos = (char *) &arg;
  tos += STACKDIR STACKSIZE;
  char n[STACKDIR(tos - (char *) &arg)];
  coarg = n; // ensure optimizer keeps n
  if (setjmp(here)) return (coarg);
  fun(arg);
  abort();
}

#define MAXTHREAD 10000

static jmp_buf thread[MAXTHREAD];
static int count = 0;

void comain(void *arg) {
  int *p = (int*)arg, i = *p;
  for (;;) {
    printf("coroutine %d at %p arg %p\n", i, (void *) &i, arg);
    int n = rand() % count;
    printf("jumping to %d\n", n);
    arg = coto(thread[i], thread[n], (char *) arg + 1);
  }
}

}
void coroutine_test() {
  while (++count < MAXTHREAD) {
    printf("spawning %d\n", count);
    cogo(thread[0], comain, &count);
  }
}

