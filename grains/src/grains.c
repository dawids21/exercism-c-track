#include "grains.h"
#include <stdint.h>
#define TOTAL 18446744073709551615ull

uint64_t square(int num)
{
    if (num < 1 || num > 64) return 0;
    uint64_t result = 1;
    for (int i = num; i > 1; i--)
    {
        result *= 2;
    }
    return result;
}

uint64_t total()
{
    return TOTAL;
}
