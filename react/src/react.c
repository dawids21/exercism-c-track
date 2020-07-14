#include "react.h"

enum types_of_cell { INPUT,
    COMPUTE_ONE,
    COMPUTE_TWO };

struct reaction {
    struct cell* output_cell;
    struct cell* input_cell_1;
    struct cell* input_cell_2;
    compute1 method1;
    compute2 method2;
};

struct callback_data {
    void* input;
    callback method;
};

struct cell {
    int value;
    struct reactor* reactor;
    enum types_of_cell type_of_cell;
    struct callback_data** callbacks;
    int num_of_callbacks;
};

struct reactor {
    struct reaction** reactions;
    int num_of_reactions;
};
