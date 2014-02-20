/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define NUM_TRACKS 5;

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};


// Finds all tracks that contain the given string.
//
// Prints track number and title.
void find_track(char *search_for)
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
	if (strstr(tracks[i], search_for)) {
	    printf("Track %i: '%s'\n", i, tracks[i]);
	}
    }
}


// Finds all tracks that match the given pattern.
//
// Prints track number and title.
void find_track_regex(char *pattern)
{
    int i, ret;
    regex_t regex;
    char *msgbuf;

    ret = regcomp(&regex, pattern, REG_EXTENDED || REG_NOSUB);
    if (ret) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }

    for (i=0; i<NUM_TRACKS; i++) {
        ret = regexec(&regex, tracks[i], 0, NULL, 0);
	if (!ret) {
	    printf("Track %i: '%s'\n", i, tracks[i]);
	} else if (ret == REG_NOMATCH) {
	    continue;
	} else {
           regerror(ret, &regex, msgbuf, sizeof(msgbuf));
           fprintf(stderr, "Regex match failed: %s\n", msgbuf);
	   exit(1);
	}
    }

    /* I'm not sure this is necessary, but it's possible that if you
       let regex go out of scope without running regfree, it leaks
       (that is, leaves some allocated memory unfreed). */
    regfree(regex);
}


int main (int argc, char *argv[])
{
    char *target = 'F';
    char *pattern = "Fr.*Fr.*";

    find_track(target);
    find_track_regex(pattern);

    return 0;
}
