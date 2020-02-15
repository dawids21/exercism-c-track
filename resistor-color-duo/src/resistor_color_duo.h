#ifndef RESISTOR_COLOR_DUO_H
#define RESISTOR_COLOR_DUO_H

#include <stdint.h>

#define ALL_COLORS {BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE}

typedef enum resistor_color_enum ALL_COLORS resistor_band_t;

uint16_t colorCode(resistor_band_t* colors);

#endif
