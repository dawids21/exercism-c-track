#include "resistor_color.h"

int array_of_colors[] = ALL_COLORS;

int colorCode(resistor_band_t color)
{
    return (int)color;
}

int* colors(void)
{
    return array_of_colors;
}
