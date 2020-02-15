#include "leap.h"

_Bool is_leap_year(const int year)
{
    if (year % 100 == 0) return (year % 400 == 0);
    return (year % 4 == 0);
}
