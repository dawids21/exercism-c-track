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
    if (is_sublist(list_to_compare, base_list, list_to_compare_element_count,
                   base_list_element_count))
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
    if (list_to_compare == NULL || base_list == NULL)
    {
        return true;
    }
    bool sublist = false;
    // swap so that it always checks if smaller list is in bigger
    if (list_to_compare_len > base_list_len)
    {
        int *temp = base_list;
        base_list = list_to_compare;
        list_to_compare = temp;
        size_t temp_len = base_list_len;
        base_list_len = list_to_compare_len;
        list_to_compare_len = temp_len;
    }
    for (size_t i = 0; i <= base_list_len - list_to_compare_len; i++)
    {
        if (!memcmp(list_to_compare, &base_list[i],
                    list_to_compare_len * sizeof(list_to_compare[0])))
        {
            sublist = true;
            break;
        }
    }
    return sublist;
}