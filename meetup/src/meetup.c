#include "meetup.h"
#include <string.h>

static int parseWeekday(const char* day_of_week);
static int firstWeekdayOfTheMonth(int month, int year);
static int checkLastDay(int month, int year);
static int calculateWeekday(int day, const char* week, int month, int year);

int meetup_day_of_month(unsigned int year, unsigned int month, const char *week, const char *day_of_week)
{
    if (month == 1 || month == 2)   //for the Zeller's congruence year is starting from March
    {
        month += 12;
        year--;
    }
    int day = parseWeekday(day_of_week) - firstWeekdayOfTheMonth(month, year) + 1;  //calculating first occurance of given weekday based on
                                                                                //difference between weekday and first weekday of the month
    if (day <= 0)   //if searched weekday is before the first weekday of the month
        day += 7;
    if (strcmp(week, "first"))
        day = calculateWeekday(day, week, month, year);
    return day;
}

static int parseWeekday(const char* day_of_week)
{
    int weekday;
    if (!strcmp(day_of_week, "Saturday"))
        weekday = 0;
    else if (!strcmp(day_of_week, "Sunday"))
        weekday = 1;
    else if (!strcmp(day_of_week, "Monday"))
        weekday = 2;
    else if (!strcmp(day_of_week, "Tuesday"))
        weekday = 3;
    else if (!strcmp(day_of_week, "Wednesday"))
        weekday = 4;
    else if (!strcmp(day_of_week, "Thursday"))
        weekday = 5;
    else if (!strcmp(day_of_week, "Friday"))
        weekday = 6;
    return weekday;
}

static int firstWeekdayOfTheMonth(int month, int year)
{
    //In this function i'm using the Zeller's congruence
    //For more information check: https://en.wikipedia.org/wiki/Zeller%27s_congruence
    int weekday = (1 + ((13*(month+1))/5) + year % 100 + (year % 100)/4 + (year/100)/4 - 2 * (year/100)) % 7;
    return (weekday < 0) ? (weekday + 7) : weekday;
}

static int checkLastDay(int month, int year)
{
    int lastDay;
    if (month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 || month == 13)
        lastDay = 31;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        lastDay = 30;
    else
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            lastDay = 29;
        else
            lastDay = 28;
    }
    return lastDay;
}

static int calculateWeekday(int day, const char* week, int month, int year)
{
    if (!strcmp(week, "second"))
        day += 7;
    else if (!strcmp(week, "third"))
        day += 14;
    else if (!strcmp(week, "fourth"))
        day += 21;
    else if (!strcmp(week, "fifth"))
        day = (day+28 > checkLastDay(month, year+1)) ? 0 : day+28;   //adding one because for algorithm i substracted one
    else if (!strcmp(week, "last"))
    {
        int lastDay = checkLastDay(month, year+1);  //same as above
        while (day <= (lastDay - 7))
            day += 7;
    }
    else if (!strcmp(week, "teenth"))
    {
        while (day < 13)
            day += 7;
    }
    return day;
}