#include "react.h"
#include <stdlib.h>

enum types_of_cell { INPUT,
    COMPUTE_ONE,
    COMPUTE_TWO };

struct reaction_one {
    cell_t* output_cell;
    cell_t* input_cell;
    compute1 method;
};

typedef struct reaction_one reaction_one_t;

struct reaction_two {
    cell_t* output_cell;
    cell_t* input_cell_one;
    cell_t* input_cell_two;
    compute2 method;
};

typedef struct reaction_two reaction_two_t;

struct callback_data {
    void* data;
    callback method;
};

typedef struct callback_data callback_data_t;

struct cell {
    int value;
    reactor_t* reactor;
    enum types_of_cell type_of_cell;
    callback_data_t** callbacks;
    int callback_next_id;
};

struct reactor {
    reaction_one_t** reactions_one;
    int num_of_reactions_one;
    reaction_two_t** reactions_two;
    int num_of_reactions_two;
};

static void add_reaction_compute_one(reactor_t*, cell_t*, cell_t*, compute1);
static void add_reaction_compute_two(reactor_t*, cell_t*, cell_t*, cell_t*, compute2);
static void perform_reactions(reactor_t*);
static void perform_callbacks(cell_t*);

reactor_t* create_reactor()
{
    reactor_t* reactor = (reactor_t*)malloc(sizeof(reactor_t));

    reactor->reactions_one = NULL;
    reactor->num_of_reactions_one = 0;
    reactor->reactions_two = NULL;
    reactor->num_of_reactions_two = 0;

    return reactor;
}

//TODO check if every malloc is freed
void destroy_reactor(reactor_t* reactor)
{
    for (int reaction_index = 0; reaction_index < reactor->num_of_reactions_one; reaction_index++) {

        free(reactor->reactions_one[reaction_index]->input_cell);

        cell_t* output_cell_to_delete = reactor->reactions_one[reaction_index]->output_cell;
        for (int callback_index = 0; callback_index < output_cell_to_delete->callback_next_id; callback_index++) {
            if (output_cell_to_delete->callbacks[callback_index] != NULL) {
                free(output_cell_to_delete->callbacks[callback_index]);
            }
        }

        free(output_cell_to_delete);
        free(reactor->reactions_one[reaction_index]);
    }

    for (int reaction_index = 0; reaction_index < reactor->num_of_reactions_two; reaction_index++) {

        free(reactor->reactions_two[reaction_index]->input_cell_one);
        free(reactor->reactions_two[reaction_index]->input_cell_two);

        cell_t* output_cell_to_delete = reactor->reactions_two[reaction_index]->output_cell;
        for (int callback_index = 0; callback_index < output_cell_to_delete->callback_next_id; callback_index++) {
            if (output_cell_to_delete->callbacks[callback_index] != NULL) {
                free(output_cell_to_delete->callbacks[callback_index]);
            }
        }

        free(output_cell_to_delete);
        free(reactor->reactions_two[reaction_index]);
    }

    free(reactor);
    reactor = NULL;
}

cell_t* create_input_cell(reactor_t* reactor, int initial_value)
{
    cell_t* cell = (cell_t*)malloc(sizeof(cell_t));

    cell->value = initial_value;
    cell->reactor = reactor;
    cell->type_of_cell = INPUT;
    cell->callbacks = NULL;
    cell->callback_next_id = 0;

    return cell;
}

cell_t* create_compute1_cell(reactor_t* reactor, cell_t* input_cell, compute1 method)
{
    cell_t* cell = (cell_t*)malloc(sizeof(cell_t));

    cell->value = method(input_cell->value);
    cell->reactor = reactor;
    cell->type_of_cell = COMPUTE_ONE;
    cell->callbacks = NULL;
    cell->callback_next_id = 0;

    add_reaction_compute_one(reactor, cell, input_cell, method);

    return cell;
}

cell_t* create_compute2_cell(reactor_t* reactor, cell_t* input_cell_one, cell_t* input_cell_two, compute2 method)
{
    cell_t* cell = (cell_t*)malloc(sizeof(cell_t));

    cell->value = method(input_cell_one->value, input_cell_two->value);
    cell->reactor = reactor;
    cell->type_of_cell = COMPUTE_TWO;
    cell->callbacks = NULL;
    cell->callback_next_id = 0;

    add_reaction_compute_two(reactor, cell, input_cell_one, input_cell_two, method);

    return cell;
}

void set_cell_value(cell_t* cell, int new_value)
{
    if (cell->type_of_cell == INPUT) {
        cell->value = new_value;
        perform_reactions(cell->reactor);
    }
}

int get_cell_value(cell_t* cell)
{
    return cell->value;
}

callback_id add_callback(cell_t* cell, void* data, callback method)
{
    int id = -1;
    callback_data_t* callback_data = (callback_data_t*)malloc(sizeof(callback_data_t));

    callback_data->data = data;
    callback_data->method = method;
    cell->callbacks[cell->callback_next_id] = callback_data;
    id = cell->callback_next_id;
    cell->callback_next_id++;

    return id;
}

void remove_callback(cell_t* cell, callback_id id)
{
    free(cell->callbacks[id]);
    cell->callbacks[id] = NULL;
}

static void add_reaction_compute_one(reactor_t* reactor, cell_t* output_cell, cell_t* input_cell, compute1 method)
{
    reaction_one_t* reaction = (reaction_one_t*)malloc(sizeof(reaction_one_t));

    reaction->input_cell = input_cell;
    reaction->output_cell = output_cell;
    reaction->method = method;

    reactor->reactions_one[reactor->num_of_reactions_one] = reaction;
    reactor->num_of_reactions_one++;
}

static void add_reaction_compute_two(reactor_t* reactor, cell_t* output_cell, cell_t* input_cell_one, cell_t* input_cell_two, compute2 method)
{
    reaction_two_t* reaction = (reaction_two_t*)malloc(sizeof(reaction_two_t));

    reaction->input_cell_one = input_cell_one;
    reaction->input_cell_two = input_cell_two;
    reaction->output_cell = output_cell;
    reaction->method = method;

    reactor->reactions_two[reactor->num_of_reactions_two] = reaction;
    reactor->num_of_reactions_two++;
}

static void perform_reactions(reactor_t* reactor)
{
    for (int reaction_index = 0; reaction_index < reactor->num_of_reactions_one; reaction_index++) {
        cell_t* input_cell = reactor->reactions_one[reaction_index]->input_cell;
        cell_t* output_cell = reactor->reactions_one[reaction_index]->output_cell;
        compute1 method = reactor->reactions_one[reaction_index]->method;
        output_cell->value = method(input_cell->value);
        perform_callbacks(output_cell);
    }

    for (int reaction_index = 0; reaction_index < reactor->num_of_reactions_two; reaction_index++) {
        cell_t* input_cell_one = reactor->reactions_two[reaction_index]->input_cell_one;
        cell_t* input_cell_two = reactor->reactions_two[reaction_index]->input_cell_two;
        cell_t* output_cell = reactor->reactions_two[reaction_index]->output_cell;
        compute2 method = reactor->reactions_two[reaction_index]->method;
        output_cell->value = method(input_cell_one->value, input_cell_two->value);
        perform_callbacks(output_cell);
    }
}

static void perform_callbacks(cell_t* cell)
{
    for (int callback_index = 0; callback_index < cell->callback_next_id; callback_index++) {
        if (cell->callbacks[callback_index] != NULL) {
            cell->callbacks[callback_index]->method(cell->callbacks[callback_index]->data, cell->value);
        }
    }
}
