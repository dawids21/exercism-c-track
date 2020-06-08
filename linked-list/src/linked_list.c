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
    list[0] = NULL;
    list[1] = NULL;
    return list;
}

bool is_list_empty(struct list_item** list)
{
    return list == NULL || list[0] == NULL;
}

bool push(struct list_item** list, ll_data_t item_data)
{
    if (list == NULL) {
        return false;
    }

    struct list_item* node = (struct list_item*)malloc(sizeof(struct list_item));
    node->data = item_data;
    node->next = NULL;

    if (list[0] == NULL) {
        node->previous = NULL;
        list[0] = node;
    } else {
        node->previous = list[1];
        list[1]->next = node;
    }

    list[1] = node;
    return true;
}

ll_data_t pop(struct list_item** list)
{
    if (is_list_empty(list)) {
        return 0;
    }

    struct list_item* tmp = list[1];
    ll_data_t tmp_value = tmp->data;

    if (list[0] == list[1]) {
        list[0] = NULL;
        list[1] = NULL;
    } else {
        list[1] = tmp->previous;
        list[1]->next = NULL;
    }

    free(tmp);

    return tmp_value;
}

ll_data_t shift(struct list_item** list)
{
    if (is_list_empty(list)) {
        return 0;
    }

    struct list_item* tmp = list[0];
    ll_data_t tmp_value = tmp->data;

    if (list[0] == list[1]) {
        list[0] = NULL;
        list[1] = NULL;
    } else {
        list[0] = tmp->next;
        list[0]->previous = NULL;
    }

    free(tmp);

    return tmp_value;
}

bool unshift(struct list_item** list, ll_data_t item_data)
{
    if (list == NULL) {
        return false;
    }

    struct list_item* node = (struct list_item*)malloc(sizeof(struct list_item));
    node->data = item_data;
    node->previous = NULL;

    if (list[0] == NULL) {
        node->next = NULL;
        list[1] = node;
    } else {
        node->next = list[0];
        list[0]->previous = node;
    }

    list[0] = node;
    return true;
}

void delete_list(struct list_item** list)
{
    if (!is_list_empty(list)) {
        while (list[0] != list[1]) {
            list[1] = list[1]->previous;
            free(list[1]->next);
        }
        free(list[0]);
    }
    free(list);
}
