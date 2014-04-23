/* Example code for Software Systems at Olin College.

Copyright 2012 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

typedef pthread_mutex_t Mutex;
typedef pthread_cond_t Cond;

typedef struct {
  int value, wakeups;
  Mutex *mutex;
  Cond *cond;
} Semaphore;

Semaphore *make_semaphore (int value);
void sem_wait (Semaphore *semaphore);
void sem_signal (Semaphore *semaphore);

void perror_exit (char *s);
void *check_malloc(int size);
