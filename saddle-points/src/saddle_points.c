#include "saddle_points.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

static void find_possible_points(saddle_points_t* possible_points, int m_columns, int m_rows, uint8_t (*matrix)[m_columns]);
static void find_actual_points(saddle_points_t* actual_points, saddle_points_t* possible_points,
                                int m_columns, int m_rows, uint8_t (*matrix)[m_columns]);

saddle_points_t* saddle_points(int m_rows, int m_columns, uint8_t (*matrix)[m_columns])
{
    saddle_point_t* points = (saddle_point_t*)calloc(m_columns > m_rows ? m_columns : m_rows, sizeof(saddle_point_t));
    saddle_points_t* actual_points = (saddle_points_t*)malloc(sizeof(saddle_points_t));
    actual_points->points = points;
    actual_points->count = 0;

    if (matrix != NULL && m_rows != 0 && m_columns != 0)
    {
        saddle_points_t possible_points;
        saddle_point_t p_point[MAX_POINTS];
        possible_points.points = p_point;
        possible_points.count = 0;

        find_possible_points(&possible_points, m_columns, m_rows, matrix);
        find_actual_points(actual_points, &possible_points, m_columns, m_rows, matrix);
    }

    return actual_points;
}

void free_saddle_points(saddle_points_t* points)
{
    if (points != NULL)
    {
        if (points->points != NULL)
        {
            free(points->points);
        }
        free(points);
    }
}

//this function finds the greatest point(s) in each row
static void find_possible_points(saddle_points_t* possible_points, int m_columns, int m_rows, uint8_t (*matrix)[m_columns])
{
    int count;
    int value;
    saddle_point_t points[m_columns];
    for (int i = 0; i < m_rows; i++)
    {
        count = 1;
        points[0].row = i;
        points[0].column = 0;
        value = matrix[points[0].row][points[0].column];
        for (int j = 1; j < m_columns; j++)
        {
            if (matrix[i][j] > value)
            {
                value = matrix[i][j];
                count = 1;
                points[0].row = i;
                points[0].column = j;
            }
            else if(matrix[i][j] == value)
            {
                points[count].row = i;
                points[count].column = j;
                count++;
            }
        }
        for (int j = 0; j < count; j++)
        {
            memcpy(&possible_points->points[possible_points->count], &points[j], sizeof(*points));
            possible_points->count++;
        }
    }
}

//this function finds if possible point is the smallest point in the column
static void find_actual_points(saddle_points_t* actual_points, saddle_points_t* possible_points,
                                int m_columns, int m_rows, uint8_t (*matrix)[m_columns])
{
    for (size_t i = 0; i < possible_points->count; i++)
    {
        bool min_value = true;
        int actual_column = possible_points->points[i].column;
        for (int j = 0; j < m_rows; j++)
        {
            if (matrix[possible_points->points[i].row][actual_column] > matrix[j][actual_column])
            {
                min_value = false;
                break;
            }
        }
        if (min_value)
        {
            memcpy(&actual_points->points[actual_points->count], &possible_points->points[i], sizeof(*possible_points->points));
            actual_points->points[actual_points->count].row++;  //tests treat first row as 1 and first column as 1
            actual_points->points[actual_points->count].column++;        
            actual_points->count++;
        }
    }
}