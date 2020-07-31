#include "etl.h"

static int calculate_output_len(const legacy_map *input,
                                const size_t input_len);

int convert(const legacy_map *input, const size_t input_len,
            new_map **output)
{
    int output_len = calculate_output_len(input, input_len);
    (void)output;
    return output_len;
}

static int calculate_output_len(const legacy_map *input,
                                const size_t input_len)
{
    //TODO
    int output_len = 0;
    return output_len;
}