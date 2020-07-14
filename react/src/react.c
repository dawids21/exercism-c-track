#include "react.h"
#include <stdlib.h>

enum types_of_cell { INPUT,
    COMPUTE_ONE,
    COMPUTE_TWO };

struct reaction_t {
    cell* output_cell;
    cell* input_cell_1;
    cell* input_cell_2;
    compute1 method1;
    compute2 method2;
};

typedef struct reaction_t reaction;

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

struct reactor {
    reaction** reactions;
    int num_of_reactions;
};
