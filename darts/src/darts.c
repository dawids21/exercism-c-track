#include "darts.h"
#include <stdint.h>
#include <math.h>

uint8_t score(coordinate_t position)
{
    double dist = sqrt((double)((position.x * position.x) + (position.y * position.y)));
    if (dist > 10) return 0;
    else if (dist <= 10 && dist > 5) return 1;
    else if (dist <= 5 && dist > 1) return 5;
    else return 10;
}
