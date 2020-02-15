#include "list_ops.h"
#include <stdlib.h>
#include <string.h>

list_t *new_list(size_t length, list_value_t values[])
{
    list_t *new_list = (list_t *) calloc(1, sizeof(size_t) + sizeof(list_value_t) * length);
    new_list->length = length;
    memcpy(new_list->values, values, sizeof(list_value_t) * length);
    return new_list;
}

list_t *append_list(list_t *list1, list_t *list2)
{
    list_t *new_list = (list_t *) calloc(1, sizeof(size_t) + sizeof(list_value_t) * (list1->length + list2->length));
    new_list->length = list1->length + list2->length;
    memcpy(new_list->values, list1->values, sizeof(list_value_t) * list1->length);
    memcpy(new_list->values + list1->length, list2->values, sizeof(list_value_t) * list2->length);
    return new_list;
}

list_t *filter_list(list_t *list, bool(*filter) (list_value_t value))
{
    size_t length = 0;
    list_value_t values[list->length];
    for (size_t i = 0; i < list->length; i++)
    {
        if (filter(list->values[i]))
        {
            values[length] = list->values[i];
            length++;
        }
    }
    list_t *new_list = (list_t *) calloc(1, sizeof(size_t) + sizeof(list_value_t) * length);
    new_list->length = length;
    memcpy(new_list->values, values, sizeof(list_value_t) * length);
    return new_list;
}

size_t length_list(list_t *list)
{
    return list->length;
}

list_t *map_list(list_t *list, list_value_t(*map) (list_value_t value))
{
    list_t *new_list = (list_t *) calloc(1, sizeof(list));
    new_list->length = list->length;
    for (size_t i = 0; i < list->length; i++)
        new_list->values[i] = map(list->values[i]);
    return new_list;
}

list_value_t foldl_list(list_t *list, list_value_t initial,
                        list_value_t(*foldl) (list_value_t value,
                                              list_value_t initial))
{
    list_value_t actual = initial;
    for (size_t i = 0; i < list->length; i++)
        actual = foldl(list->values[i], actual);
    return actual;
}

list_value_t foldr_list(list_t *list, list_value_t initial,
                        list_value_t(*foldr) (list_value_t value,
                                              list_value_t initial))
{
    list_value_t actual = initial;
    for (size_t i = list->length; i > 0; i--)
        actual = foldr(list->values[i-1], actual);
    return actual;
}

list_t *reverse_list(list_t *list)
{
    list_t *new_list = (list_t *) calloc (1, sizeof(list));
    for (size_t i = list->length; i > 0; i--)
    {
        new_list->values[new_list->length] = list->values[i-1];
        new_list->length++;
    }
    return new_list;
}

void delete_list(list_t *list)
{
    free(list);
}