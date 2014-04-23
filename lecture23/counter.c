/* Example code for Software Systems at Olin College.

Copyright 2012 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "semaphore.h"

#define NUM_CHILDREN 2

typedef struct {
  int counter;
  int end;
  int *array;
  Semaphore *mutex;
} Shared;

Shared *make_shared (int end)
{
  int i;
  Shared *shared = check_malloc (sizeof (Shared));

  shared->counter = 0;
  shared->end = end;

  shared->array = check_malloc (shared->end * sizeof(int));
  for (i=0; i<shared->end; i++) {
    shared->array[i] = 0;
  }
  shared->mutex = make_semaphore(1);
  return shared;
}

pthread_t make_thread(void *(*entry)(void *), Shared *shared)
{
  int ret;
  pthread_t thread;

  ret = pthread_create (&thread, NULL, entry, (void *) shared);
  if (ret != 0) perror_exit ("pthread_create failed");
  return thread;
}

void join_thread (pthread_t thread)
{
  int ret = pthread_join (thread, NULL);
  if (ret == -1) perror_exit ("pthread_join failed");
}

void child_code (Shared *shared)
{
  int index;

  printf ("Starting child at counter %d\n", shared->counter);

  while (1) {
    sem_wait(shared->mutex);
    index = shared->counter++;
    sem_signal(shared->mutex);

    if (index >= shared->end) {
      return;
    }

    shared->array[index]++;

    if (index % 10000 == 0) {
      printf ("%d\n", index);
    }
  }
}

void *entry (void *arg)
{
  Shared *shared = (Shared *) arg;
  child_code (shared);
  printf ("Child done.\n");
  pthread_exit (NULL);
}

void check_array (Shared *shared)
{
  int i, errors=0;

  printf ("Checking...\n");

  for (i=0; i<shared->end; i++) {
    if (shared->array[i] != 1) errors++;
  }
  printf ("%d errors.\n", errors);
}

int main ()
{
  int i;
  pthread_t child[NUM_CHILDREN];

  Shared *shared = make_shared (100000);

  for (i=0; i<NUM_CHILDREN; i++) {
    child[i] = make_thread (entry, shared);
  }

  for (i=0; i<NUM_CHILDREN; i++) {
    join_thread (child[i]);
  }

  check_array (shared);
  return 0;
}
