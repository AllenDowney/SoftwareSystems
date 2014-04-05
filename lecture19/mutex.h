/* Example code for Software Systems at Olin College.

Copyright 2012 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <pthread.h>

typedef struct {
  int value;
  pthread_mutex_t mutex[1];
} Lock;

Lock *make_lock ();
void acquire (Lock *lock);
void release (Lock *lock);
