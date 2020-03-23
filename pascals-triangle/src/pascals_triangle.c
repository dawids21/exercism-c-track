#include "pascals_triangle.h"

static int calculate_row_size(int num_of_rows);

void free_triangle(size_t **triangle, size_t num_of_rows)
{
    if (triangle != NULL)
    {
        for (size_t i = 0; i < num_of_rows; i++)
        {
            if (triangle[i] != 0)
            {
                free(triangle[i]);
                triangle[i] = NULL;
            }
        }
        free(triangle);
        triangle = NULL;
    }
}

size_t **create_triangle(int num_of_rows)
{
    size_t **triangle = NULL;
    if (num_of_rows == 0)
    {
        triangle = (size_t **)malloc(sizeof(size_t *));
        triangle[0] = (size_t *)malloc(sizeof(size_t));
        return triangle;
    }
    triangle = (size_t **)malloc(num_of_rows * sizeof(size_t *));
    int row_size = calculate_row_size(num_of_rows);
    for (int i = 0; i < num_of_rows; i++)
    {
        triangle[i] = (size_t *)malloc(row_size * sizeof(size_t));
    }
    return triangle;
}

static int calculate_row_size(int num_of_rows)
{
    return 2 * num_of_rows + 1;
}