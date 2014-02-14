/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Returns a heap-allocated string that contains the letters
   from the input strings, interleaved.
*/
char *interleave(char *s1, char *s2)
{
    int size;
    char *dest;
    int i=0, j=0, k=0;

    size = strlen(s1) + strlen(s2) + 1;

    dest = malloc (size * sizeof(char));

    for (k=0; k<size-1; ) {
	if (s1[i]) {
	    dest[k++] = s1[i++];
	}
	if (s2[j]) {
	    dest[k++] = s2[j++];
	}
    }
    dest[k] = '\0';
    return dest;
}


int main ()
{
    char *s = interleave("clips", "aloe");
    printf("%s\n", s);
    return 0;
}
