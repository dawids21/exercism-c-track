#include "resistor_color_trio.h"

static const unit_t TABLE[] = {OHMS, KILOOHMS};

resistor_value_t color_code(resistor_band_t* bands)
{
    resistor_value_t resistor;
    resistor.value = (bands[0] * 10 + bands[1]);
    int unit = 0;
    for (unsigned int i=0; i < bands[2]; i++)
    {
        resistor.value *= 10;
        if (i % 3 == 1) 
            unit++;
        if (resistor.value % 1000 == 0)
            resistor.value /= 1000;
    }
    resistor.unit = TABLE[unit];
    return resistor;
}