/* Example from Figure 2.4 of Hailperin, Operating Systems and Middleware.

Copyright 2012 Max Hailperin
License: Creative Commons Attribution-ShareAlike 3.0

Modified by Allen Downey.
 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>


static void *child(void *ignored)
{
    sleep(3);
    printf("Child is done sleeping 3 seconds.\n");
    return NULL;
}


int main(int argc, char *argv[])
{
    pthread_t child_thread;
    int code;

    code = pthread_create(&child_thread, NULL, child, NULL);
    if (code) {
	fprintf(stderr, "pthread_create failed with code %d\n", code);
    }
    sleep(5);
    printf("Parent is done sleeping 5 seconds.\n");
    return 0;
}
