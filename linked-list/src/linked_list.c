#include "linked_list.h"
#include <stdlib.h>

struct list_item
{
    struct list_item *previous;
    struct list_item *next;
    ll_data_t data;
};

struct list_item **new_list(void)
{
    struct list_item **list = (struct list_item **)malloc(sizeof(struct list_item *) * 2);
    *list = NULL;
    *(list + 1) = NULL;
    return list;
}