#include <stdio.h>
#include <time.h>
#define GIGASECOND 1000000000
time_t gigasecond_after(time_t time)
{
    return time + GIGASECOND;
}
