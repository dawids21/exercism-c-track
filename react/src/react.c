#include "react.h"
#include <stdlib.h>

enum types_of_cell { INPUT,
    COMPUTE_ONE,
    COMPUTE_TWO };

struct reaction_one_t {
    cell* output_cell;
    cell* input_cell;
    compute1 method;
};

typedef struct reaction_one_t reaction_one;

struct reaction_two_t {
    cell* output_cell;
    cell* input_cell_one;
    cell* input_cell_two;
    compute1 method;
};

typedef struct reaction_two_t reaction_two;

struct callback_data_t {
    void* input;
    callback method;
};

typedef struct callback_data_t callback_data;

struct cell_t {
    int value;
    reactor* reactor;
    enum types_of_cell type_of_cell;
    callback_data** callbacks;
    int num_of_callbacks;
};

struct reactor_t {
    reaction_one** reactions_one;
    int num_of_reactions_one;
    reaction_two** reactions_two;
    int num_of_reactions_two;
};
