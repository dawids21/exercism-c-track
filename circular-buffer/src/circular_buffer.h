#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#define HEAD 1
#define TAIL 2

typedef int buffer_value_t;
typedef struct 
{
    buffer_value_t* buffer;
    buffer_value_t* head;
    buffer_value_t* tail;
    bool is_full;
    size_t capacity;
} circular_buffer_t;

circular_buffer_t* new_circular_buffer(size_t capacity);
int16_t write(circular_buffer_t* circular_buffer, buffer_value_t value);
int16_t overwrite(circular_buffer_t* circular_buffer, buffer_value_t value);
int16_t read(circular_buffer_t* circular_buffer, buffer_value_t* value);
void clear_buffer(circular_buffer_t* circular_buffer);
void delete_buffer(circular_buffer_t* circular_buffer);

#endif
