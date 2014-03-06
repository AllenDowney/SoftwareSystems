#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/types.h>
#include <unistd.h>

#include "rand.c"

main (int argc, char *argv[])
{
  int i;
  float f;
  double t0, t1;
  int iters = 1000;
  int seed = 17;

  srandom (seed);

  for (i=0; i<iters; i++) {
    f = my_random_float();
    printf ("%f\n", f);
  }
}
