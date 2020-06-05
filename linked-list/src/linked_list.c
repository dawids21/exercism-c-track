#include "linked_list.h"

struct list_item
{
    struct list_item *previous;
    struct list_item *next;
    ll_data_t data;
};
