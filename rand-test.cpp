//
// Created by lizgao on 7/25/18.
//

#include <stdlib.h>
#include <stdio.h>

void random_test()
{
    int j, r, nloops;
    unsigned int seed;

   seed = 1000;
    nloops = 100;

   //srand(seed);
    for (j = 0; j < nloops; j++) {
        r =  rand();
        printf("%d\n", r);
    }
}