#ifndef RESISTOR_COLOR_H
#define RESISTOR_COLOR_H

#define ALL_COLORS {BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE}

typedef enum resistor_color_enum ALL_COLORS resistor_band_t;

int colorCode(resistor_band_t color);
int* colors(void);

#endif
