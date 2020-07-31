#include "etl.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

static int calculate_output_len(const legacy_map *input,
                                const size_t input_len);
static void insert_index(new_map *map, const size_t capacity,
                         const char key, const int value);
static void move_elements_by_one(const new_map *map,
                                 size_t start_index,
                                 size_t capacity);

int convert(const legacy_map *input, const size_t input_len,
            new_map **output)
{
    int output_len = calculate_output_len(input, input_len);
    *output = (new_map *)calloc(output_len, sizeof(new_map));
    for (size_t input_index = 0; input_index < input_len; input_index++)
    {
        int value = input[input_index].value;
        for (size_t keys_index = 0;
             keys_index < strlen(input[input_index].keys);
             keys_index++)
        {
            insert_index(*output, output_len,
                         input[input_index].keys[keys_index],
                         value);
        }
    }
    return output_len;
}

static int calculate_output_len(const legacy_map *input,
                                const size_t input_len)
{
    int output_len = 0;
    for (size_t i = 0; i < input_len; i++)
    {
        output_len += strlen(input[i].keys);
    }
    return output_len;
}

static void insert_index(new_map *map, const size_t capacity,
                         const char key, const int value)
{
    char insert_key = tolower(key);
    for (size_t i = 0; i < capacity; i++)
    {
        if (map[i].key == '\0')
        {
            map[i].key = insert_key;
            map[i].value = value;
            break;
        }
        else if (i + 1 < capacity && map[i].key < insert_key && map[i + 1].key > insert_key)
        {
            move_elements_by_one(map, i + 1, capacity);
            map[i + 1].key = insert_key;
            map[i + 1].value = value;
            break;
        }
    }
}