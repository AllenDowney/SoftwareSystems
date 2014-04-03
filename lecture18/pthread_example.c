/* Example code for Software Systems at Olin College.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <errno.h>

/* This typedef is the C equivalent of creating a new class named
   Card, with the following instance variables, and no methods */

typedef struct {
  int rank, suit;
} Card;

/* The entry procedure is where the child thread will start executing.
   When the child thread starts, its stack will contain only the
   activation record for entry.  When we return from entry, the thread
   terminates, just as when the parent thread returns from main, it
   terminates. */

void *entry (void *arg)
{
  /* The entry procedure takes a single pointer as an argument, but
     it can be a pointer to anything, including structures that are
     in the heap (as in this case) */

  Card *card = (Card *) arg;
  int ret;

  /* I put this sleep statement here to force the parent to run first */
  sleep(1);   

  /* alternatively, I could use... */

  ret = sched_yield ();
  if (ret == -1) {
    perror ("yield failed");
    exit (-1);
  }

  printf ("Child: rank = %d, suit = %d\n", card->rank, card->suit);
  pthread_exit (NULL);
}

/* the parent thread starts executing in main */

int main ()
{
  /* the parent thread creates a new object in the heap using malloc */
  
  Card *card = (Card *) malloc (sizeof (Card));
  int i, ret;
  pthread_t child;

  card->rank = 6;
  card->suit = 3;

  /* the parent thread creates the new thread, passing
     a pointer to card as an argument */

  ret = pthread_create (&child, NULL, entry, (void *) card);
  if (ret == -1) {
    perror ("pthread_create failed");
    exit (-1);
  }

  /* when the parent thread modifies the card, the child sees the change! */
  card->rank = 7;
  printf ("Parent: rank = %d, suit = %d\n", card->rank, card->suit);

  /* if the parent is done with the child, it detaches it, which
     means that when the child completes, its resources will be
     reclaimed */

  ret = pthread_detach (child);
  if (ret == -1) {
    perror ("pthread_detach failed");
    exit (-1);
  }

  /* if the parent dies before the child, it usually takes the child
     with it!  Unless, that is, the parent calls pthread_exit, which
     forces it to wait for all threads to terminate. */

  pthread_exit (NULL);
}

