//
// Created by lizgao on 9/14/18.
//

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

void fork_test(void)
{
   int i;
   for(i=0; i<2; i++){
      fork();
      printf("-\n");
   }

   wait(NULL);
   wait(NULL);
}