#include "linked_list.h"
#include <stdlib.h>
#include <stdbool.h>

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

bool is_list_empty(struct list_item **list)
{
    return *list == NULL;
}

bool push(struct list_item **list, ll_data_t item_data)
{
    (void)list;
    (void)item_data;
    return true;
}

ll_data_t pop(struct list_item **list)
{
    (void)list;
    return 0;
}

ll_data_t shift(struct list_item **list)
{
    (void)list;
    return 0;
}

bool unshift(struct list_item **list, ll_data_t item_data)
{
    (void)list;
    (void)item_data;
    return true;
}

void delete_list(struct list_item **list)
{
    (void)list;
}