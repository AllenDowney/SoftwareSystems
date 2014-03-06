#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

// Get current time as seconds elapsed since the Epoch.
time_t get_current_time() {
    time_t current_time = time(NULL);
 
    if (current_time == ((time_t)-1))
    {
        (void) fprintf(stderr, "Failure to compute the current time.");
        exit(EXIT_FAILURE);
    }
    return current_time;
}

// Converts time_t to local time format. 
char *convert_time(time_t t) {
    char *c_time_string = ctime(&t);
    if (c_time_string == NULL)
    {
        (void) fprintf(stderr, "Failure to convert the current time.");
        exit(EXIT_FAILURE);
    }
 
    //return c_time_string;
    return strdup(c_time_string);
}

// Interval definition
typedef struct {
    time_t start;
    time_t end;
} Interval;

// Returns a new Interval with the given start and end times.
// If unable to allocate, prints an error message and exits.
Interval *make_interval(time_t start, time_t end) {
    // fill this in
    return NULL;
}

// Computes the duration of an Interval using difftime.
double interval_duration(Interval *interval) {
    // fill this in
    return 0.0;
}

// Frees an Interval.
void free_interval(Interval *interval) {
    // fill this in
}

// Prints an interval in local time.
void print_interval(Interval *interval) {
    char *start = convert_time(interval->start);
    char *end = convert_time(interval->end);
    printf("From %s to  %s\n", start, end);
}

int main(void)
{
    time_t start = get_current_time();
 
    sleep(1);
    time_t end = get_current_time();

    Interval *interval = make_interval(start, end);
    double diff = interval_duration(interval);
    print_interval(interval);
    free_interval(interval);

    (void) printf("Elapsed time in seconds %lf\n", diff);

    return EXIT_SUCCESS;
}
