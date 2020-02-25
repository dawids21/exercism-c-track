#include "clock.h"
#include <stdio.h>
#include <string.h>

clock_t clock_create(int hour, int minute)
{
    clock_t clock;
    int time = hour*MINUTES_IN_HOUR + minute;
    sprintf(clock.text, "%02d:%02d", (time/60)%24, time%60);
    return clock;
}

clock_t clock_add(clock_t clock, int minute_add)
{
    int hours, minutes;
    int time;
    sscanf(clock.text, "%d:%d", &hours, &minutes); //Check if it works
    time = hours*MINUTES_IN_HOUR + minutes + minute_add;
    if (time >= MINUTES_IN_24_HOURS)
    {
        time -= MINUTES_IN_24_HOURS;
    }
    sprintf(clock.text, "%02d:%02d", time/60, time%60);
    return clock;
}

clock_t clock_subtract(clock_t clock, int minute_subtract)
{
    int hours, minutes;
    int time;
    sscanf(clock.text, "%d:%d", &hours, &minutes); //Check if it works
    time = hours*MINUTES_IN_HOUR + minutes - minute_subtract;
    if (time < 0)
    {
        time += MINUTES_IN_24_HOURS;
    }
    sprintf(clock.text, "%02d:%02d", time/60, time%60);
    return clock;
}

bool clock_is_equal(clock_t a, clock_t b)
{
    bool is_equal = false;
    if (strcmp(a.text, b.text) == 0)
    {
        is_equal = true;
    }
    return is_equal;
}