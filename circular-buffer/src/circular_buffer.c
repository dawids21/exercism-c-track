#include "circular_buffer.h"
#include <stdlib.h>
#include <errno.h>

extern int errno;

static void move_pointer(circular_buffer_t* circular_buffer, buffer_value_t** pointer);

circular_buffer_t* new_circular_buffer(size_t capacity)
{
    static circular_buffer_t circular_struct;
    circular_buffer_t* circular_buffer = &circular_struct;
    circular_buffer->buffer = (buffer_value_t*)malloc(capacity * sizeof(buffer_value_t));
    if (circular_buffer->buffer == NULL)
    {
        errno = ENOMEM;
        exit(EXIT_FAILURE);
    }
    circular_buffer->head = circular_buffer->buffer;
    circular_buffer->tail = circular_buffer->buffer;
    circular_buffer->is_full = false;
    circular_buffer->capacity = capacity;
    return circular_buffer;
}

int16_t write(circular_buffer_t* circular_buffer, buffer_value_t value)
{
    int16_t return_status;
    if(circular_buffer == NULL)
    {
        errno = EINVAL;
        return_status = EXIT_FAILURE;
    }
    else
    {
        if (!circular_buffer->is_full)
        {
            *circular_buffer->head = value;
            move_pointer(circular_buffer, &circular_buffer->head);
            if (circular_buffer->head == circular_buffer->tail)
            {
                circular_buffer->is_full = true;
            }
            return_status = EXIT_SUCCESS;
        }
        else
        {
            return_status = EXIT_FAILURE;
            errno = ENOBUFS;
        }
    }
    return return_status;
}

int16_t overwrite(circular_buffer_t* circular_buffer, buffer_value_t value)
{
    int16_t return_status;
    if (circular_buffer == NULL)
    {
        errno = EINVAL;
        return_status = EXIT_FAILURE;
    }
    else
    {
        *circular_buffer->head = value;
        if (circular_buffer->is_full)
        {
            move_pointer(circular_buffer, &circular_buffer->tail);
        }
        move_pointer(circular_buffer, &circular_buffer->head);
        if (circular_buffer->head == circular_buffer->tail)
        {
            circular_buffer->is_full = true;
        }
        return_status = EXIT_SUCCESS;
    }
    return return_status;
}

int16_t read(circular_buffer_t* circular_buffer, buffer_value_t* value)
{
    int16_t return_status;
    if (circular_buffer == NULL || value == NULL)
    {
        errno = EINVAL;
        return_status = EXIT_FAILURE;
    }
    else
    {
        if (circular_buffer->head != circular_buffer->tail || circular_buffer->is_full)
        {
            *value = *circular_buffer->tail;
            move_pointer(circular_buffer, &circular_buffer->tail);
            if (circular_buffer->is_full)
            {
                circular_buffer->is_full = false;
            }
            return_status = EXIT_SUCCESS;
        }
        else 
        {
            return_status = EXIT_FAILURE;
            errno = ENODATA;
        }
    }
    return return_status;
}

void clear_buffer(circular_buffer_t* circular_buffer)
{
    if (circular_buffer == NULL)
    {
        errno = EINVAL;
    }
    circular_buffer->tail = circular_buffer->head;
    if (circular_buffer->is_full)
    {
        circular_buffer->is_full = false;
    }
}

void delete_buffer(circular_buffer_t* circular_buffer)
{
    if (circular_buffer == NULL)
    {
        errno = EINVAL;
    }
    free(circular_buffer->buffer);
    circular_buffer->buffer = NULL;
}

static void move_pointer(circular_buffer_t* circular_buffer, buffer_value_t** pointer)
{
    (*pointer)++;
    if ((*pointer - circular_buffer->buffer) == (int)circular_buffer->capacity)
    {
        *pointer = circular_buffer->buffer;
    }
}