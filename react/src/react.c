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
    compute1 method;
};

typedef struct reaction_two reaction_two_t;

struct callback_data {
    void* input;
    callback method;
};

typedef struct callback_data callback_data_t;

struct cell {
    int value;
    reactor_t* reactor;
    enum types_of_cell type_of_cell;
    callback_data_t** callbacks;
    int num_of_callbacks;
};

struct reactor {
    reaction_one_t** reactions_one;
    int num_of_reactions_one;
    reaction_two_t** reactions_two;
    int num_of_reactions_two;
};

static void add_reaction_compute_one(reactor_t* reactor, cell_t* output_cell, cell_t* input_cell, compute1 method);                         //TODO
static void add_reaction_compute_two(reactor_t* reactor, cell_t* output_cell, cell_t* input_cell_1, cell_t* input_cell_2, compute2 method); //TODO

reactor_t* create_reactor()
{
    reactor_t* reactor = (reactor_t*)malloc(sizeof(reactor_t));

    reactor->reactions_one = NULL;
    reactor->num_of_reactions_one = 0;
    reactor->reactions_two = NULL;
    reactor->num_of_reactions_two = 0;

    return reactor;
}

void destroy_reactor(reactor_t* reactor)
{
    for (int i = 0; i < reactor->num_of_reactions_one; i++) {
        free(reactor->reactions_one[i]->input_cell);
        free(reactor->reactions_one[i]->output_cell);
    }
    for (int i = 0; i < reactor->num_of_reactions_two; i++) {
        free(reactor->reactions_two[i]->input_cell_one);
        free(reactor->reactions_two[i]->input_cell_two);
        free(reactor->reactions_two[i]->output_cell);
    }

    free(reactor);
}

cell_t* create_input_cell(reactor_t* reactor, int initial_value)
{
    cell_t* cell = (cell_t*)malloc(sizeof(cell_t));

    cell->value = initial_value;
    cell->reactor = reactor;
    cell->type_of_cell = INPUT;
    cell->callbacks = NULL;
    cell->num_of_callbacks = 0;

    return cell;
}

cell_t* create_compute1_cell(reactor_t* reactor, cell_t* input_cell, compute1 method)
{
    cell_t* cell = (cell_t*)malloc(sizeof(cell_t));

    cell->value = method(input_cell->value);
    cell->reactor = reactor;
    cell->type_of_cell = COMPUTE_ONE;
    cell->callbacks = NULL;
    cell->num_of_callbacks = 0;

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
    cell->num_of_callbacks = 0;

    add_reaction_compute_two(reactor, cell, input_cell_one, input_cell_two, method);

    return cell;
}
