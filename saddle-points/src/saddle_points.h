#ifndef SADDLE_POINTS_H
#define SADDLE_POINTS_H

#include <stdint.h>
#include <stdlib.h>

#define MAX_POINTS 20

typedef struct 
{
    int row;
    int column;
} saddle_point_t;

typedef struct 
{
    saddle_point_t* points;
    size_t count;
} saddle_points_t;

saddle_points_t* saddle_points(int m_columns, int m_rows, uint8_t (*matrix)[m_columns]);
void free_saddle_points(saddle_points_t* points);

#endif
