#ifndef REACT_H
#define REACT_H

struct reactor_t;
struct cell_t;

typedef struct cell_t cell;
typedef struct reactor_t reactor;

typedef int (*compute1)(int);
typedef int (*compute2)(int, int);

reactor* create_reactor();
// destroy_reactor should free all cells created under that reactor.
void destroy_reactor(reactor*);

cell* create_input_cell(reactor*, int initial_value);
cell* create_compute1_cell(reactor*, cell*, compute1);
cell* create_compute2_cell(reactor*, cell*,
    cell*, compute2);

int get_cell_value(cell*);
void set_cell_value(cell*, int new_value);

typedef void (*callback)(void*, int);
typedef int callback_id;

// The callback should be called with the same void * given in add_callback.
callback_id add_callback(cell*, void*, callback);
void remove_callback(cell*, callback_id);

#endif
