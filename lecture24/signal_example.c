/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

Based on an example from 
https://raw.githubusercontent.com/twcamper/head-first-c/master/10/math-master.c

Based on an example in Head First C.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int score = 0;

int catch_signal(int sig, void (*handler) (int)) {
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    return sigaction(sig, &action, NULL);
}

void end_game(int sig)
{
    printf("\nFinal score: %i\n", score);
    exit(EXIT_SUCCESS);
}

void times_up(int sig) {
    puts("\nTIME'S UP!");
    raise(SIGINT);
}

int main(void) {
    int a, b, answer;
    char txt[4];
    catch_signal(SIGALRM, times_up);
    catch_signal(SIGINT, end_game);
    srandom((unsigned int) time(NULL));

    while(1) {
	a = rand() % 11;
	b = rand() % 11;
	printf("\nWhat is %d times %d? ", a, b);

	alarm(5);
	fgets(txt, 4, stdin);

	answer = atoi(txt);
	if (answer == a * b) {
	    score++;
	} else {
	    printf("\nWrong! Score: %i\n", score);
	}
    }
    return 0;
}
