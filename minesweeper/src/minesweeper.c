#include "minesweeper.h"
#include <stdlib.h>
#include <string.h>

static int how_many_mines(const char **minefield,
                          const size_t rows,
                          const size_t columns,
                          const int col_index,
                          const int row_index);

char **annotate(const char **minefield, const size_t rows)
{
    if (minefield == NULL)
    {
        return NULL;
    }

    char **output_field = (char **)calloc(rows + 1, sizeof(char *));
    size_t columns = strlen(minefield[0]);
    for (size_t i = 0; i < rows; i++)
    {
        output_field[i] = (char *)calloc(columns + 1, sizeof(char));
    }

    for (size_t row_index = 0; row_index < rows; row_index++)
    {
        for (size_t col_index = 0; col_index < columns; col_index++)
        {
            if (minefield[row_index][col_index] == '*')
            {
                output_field[row_index][col_index] = '*';
            }
            else
            {
                int mines = how_many_mines(minefield, rows, columns, col_index, row_index);
                output_field[row_index][col_index] = mines ? mines + '0' : ' ';
            }
        }
    }
    return output_field;
}

void free_annotation(char **annotation)
{
    if (annotation == NULL)
    {
        return;
    }

    for (int i = 0; annotation[i] != NULL; i++)
    {
        free(annotation[i]);
    }
    free(annotation);
    annotation = NULL;
}

static int how_many_mines(const char **minefield,
                          const size_t rows,
                          const size_t columns,
                          const int col_index,
                          const int row_index)
{
    int num_of_mines = 0;
    for (int i = -1; i <= 1; i++)
    {
        int y = row_index + i;
        if (y < 0 || y >= (int)rows)
        {
            continue;
        }

        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            int x = col_index + j;
            if (x < 0 || x >= (int)columns)
            {
                continue;
            }
            if (minefield[y][x] == '*')
            {
                num_of_mines++;
            }
        }
    }
    return num_of_mines;
}