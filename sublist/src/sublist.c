#include "sublist.h"
#include <stdbool.h>
#include <string.h>

static bool is_sublist(int *list_to_compare, int *base_list,
                       size_t list_to_compare_len, size_t base_list_len);
comparison_result_t check_lists(int *list_to_compare, int *base_list,
                                size_t list_to_compare_element_count,
                                size_t base_list_element_count)
{
    comparison_result_t result = UNEQUAL;
    if (is_sublist(list_to_compare, base_list, list_to_compare_element_count, base_list_element_count))
    {
        if (list_to_compare_element_count > base_list_element_count)
        {
            result = SUPERLIST;
        }
        else if (list_to_compare_element_count == base_list_element_count)
        {
            result = EQUAL;
        }
        else
        {
            result = SUBLIST;
        }
    }
    return result;
}

static bool is_sublist(int *list_to_compare, int *base_list,
                       size_t list_to_compare_len, size_t base_list_len)
{
    bool sublist = false;
    return sublist;
}