#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/types.h>
#include <unistd.h>

double get_seconds() {
  double user, sys;
  struct rusage r;

  getrusage (RUSAGE_SELF, &r);

  user = r.ru_utime.tv_sec * 1000.0 + r.ru_utime.tv_usec / 1000.0;
  sys = r.ru_stime.tv_sec * 1000.0 + r.ru_stime.tv_usec / 1000.0;

  // printf("%lf\n", user);

  return user+sys;
}
 
double time_func(int iters, float (*func)())
{
  int i;
  float f;
  double t0, t1;

  srandom (time (NULL));

  t0 = get_seconds();
  for (i=0; i<iters; i++) {
    f = func();

  }
  t1 = get_seconds();
  return t1 - t0;
}

#include "rand.c"

main (int argc, char *argv[])
{
  int i;
  float f;
  double t0, t1;
  int iters = 1000000000;
  int seed = 17;

  srandom (seed);
  t0 = get_seconds();
  for (i=0; i<iters; i++) {
    f = dummy();
  }
  t1 = get_seconds();
  printf ("dummy \t %f ms\n", t1 - t0);
    

  srandom (seed);
  t0 = get_seconds();
  for (i=0; i<iters; i++) {
    f = dummy();
  }
  t1 = get_seconds();
  printf ("dummy \t %f ms\n", t1 - t0);
   

  srandom (seed);
  t0 = get_seconds();
  for (i=0; i<iters; i++) {
    f = dummy2();
  }
  t1 = get_seconds();
  printf ("dummy2 \t %f ms\n", t1 - t0);    
    

  srandom (seed);
  t0 = get_seconds();
  for (i=0; i<iters; i++) {
    f = dummy2();
  }
  t1 = get_seconds();
  printf ("dummy2 \t %f ms\n", t1 - t0);    
    

  srandom (seed);
  t0 = get_seconds();
  for (i=0; i<iters; i++) {
    f = my_random_float();
  }
  t1 = get_seconds();
  printf ("mine \t %f ms\n", t1 - t0);
   

  srandom (seed);
  t0 = get_seconds();
  for (i=0; i<iters; i++) {
    f = my_random_float();
  }
  t1 = get_seconds();
  printf ("mine \t %f ms\n", t1 - t0);
    

  srandom (seed);
  t0 = get_seconds();
  for (i=0; i<iters; i++) {
    f = random_float();
  }
  t1 = get_seconds();
  printf ("theirs \t %f ms\n", t1 - t0);
    

  srandom (seed);
  t0 = get_seconds();
  for (i=0; i<iters; i++) {
    f = random_float();
  }
  t1 = get_seconds();
  printf ("theirs \t %f ms\n", t1 - t0);    
}
