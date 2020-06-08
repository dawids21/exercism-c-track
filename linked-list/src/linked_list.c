#include "linked_list.h"
#include <stdbool.h>
#include <stdlib.h>

struct list_item {
    struct list_item* previous;
    struct list_item* next;
    ll_data_t data;
};

struct list_item** new_list(void)
{
    struct list_item** list = (struct list_item**)malloc(sizeof(struct list_item*) * 2);
    *list = NULL;
    *(list + 1) = NULL;
    return list;
}

bool is_list_empty(struct list_item** list)
{
    return list == NULL || *list == NULL;
}

bool push(struct list_item** list, ll_data_t item_data)
{
    if (list == NULL)
        return false;

    struct list_item* node = (struct list_item*)malloc(sizeof(struct list_item));
    node->data = item_data;
    node->previous = *(list + 1);
    node->next = NULL;
    (*(list + 1))->next = node;
    *(list + 1) = node;
    return true;
}

ll_data_t pop(struct list_item** list)
{
    (void)list;
    return 0;
}

ll_data_t shift(struct list_item** list)
{
    (void)list;
    return 0;
}

bool unshift(struct list_item** list, ll_data_t item_data)
{
    (void)list;
    (void)item_data;
    return true;
}

void delete_list(struct list_item** list)
{
    if (!is_list_empty(list)) {
        while (*list != *(list + 1)) {
            *(list + 1) = (*(list + 1))->previous;
            free((*(list + 1))->next);
        }
        free(*list);
    }
    free(list);
}
