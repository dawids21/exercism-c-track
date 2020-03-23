#include "pascals_triangle.h"

static void add_numbers(size_t **triangle, int num_of_rows);

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
    if (num_of_rows < 0)
    {
        return triangle;
    }
    else if (num_of_rows == 0)
    {
        triangle = (size_t **)malloc(sizeof(size_t *));
        triangle[0] = (size_t *)calloc(1, sizeof(size_t));
        return triangle;
    }
    triangle = (size_t **)malloc(num_of_rows * sizeof(size_t *));
    for (int i = 0; i < num_of_rows; i++)
    {
        triangle[i] = (size_t *)calloc(num_of_rows, sizeof(size_t));
    }
    add_numbers(triangle, num_of_rows);
    return triangle;
}

static void add_numbers(size_t **triangle, int num_of_rows)
{
    triangle[0][0] = 1;
    for (int i = 1; i < num_of_rows; i++)
    {
        triangle[i][0] = 1;
        for (int j = 1; j < num_of_rows; j++)
        {
            int number = triangle[i - 1][j - 1] + triangle[i - 1][j];
            triangle[i][j] = number;
            if (number == 1)
            {
                break;
            }
        }
    }
}