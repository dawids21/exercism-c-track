#include "etl.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

static int calculate_output_len(const legacy_map *input,
                                const size_t input_len);
static void add_entry(new_map *map, const int index,
                      const char key, const int value);
static int compare_entries(const void *p1, const void *p2);

int convert(const legacy_map *input, const size_t input_len,
            new_map **output)
{
    int output_len = calculate_output_len(input, input_len);
    *output = (new_map *)calloc(output_len, sizeof(new_map));
    int output_index = 0;
    for (size_t input_index = 0; input_index < input_len; input_index++)
    {
        int value = input[input_index].value;
        for (size_t keys_index = 0;
             keys_index < strlen(input[input_index].keys);
             keys_index++)
        {
            add_entry(*output, output_index,
                      input[input_index].keys[keys_index],
                      value);
            output_index++;
        }
    }
    qsort(*output, output_len, sizeof(new_map), compare_entries);
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

static void add_entry(new_map *map, const int index,
                      const char key, const int value)
{
    map[index].key = tolower(key);
    map[index].value = value;
}

static int compare_entries(const void *p1, const void *p2)
{
    const new_map *entry_1 = p1;
    const new_map *entry_2 = p2;
    return entry_1->key - entry_2->key;
}