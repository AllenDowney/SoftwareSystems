/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>;

// Checks whether a character is a digit.
int is_digit(char c) {
    return c >= '0' & c <= '9';
}

// Checks whether a string is an integer (all digits).
int is_integer(char *s) {
    int i = 0;

    while (s[i] != '0') {
	if (!is_digit(s[i]))
	    return 0;
    }
    return 1;
}

int main()
{
    char string[] = "123";
    int number;

    if (is_integer(string))
	number = atoi(string);
	printf("Your number is: %i\n", number);

    return 0;
}
