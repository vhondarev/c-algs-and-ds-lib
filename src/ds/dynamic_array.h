#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    size_t size;
    size_t capacity;
} dyn_int_arr_s;

dyn_int_arr_s *dyn_int_arr_create();

bool dyn_int_arr_init_mem(dyn_int_arr_s *arr);

int dyn_int_arr_realloc_mem(dyn_int_arr_s *arr);

void dyn_int_arr_destroy(dyn_int_arr_s *arr);

bool dyn_int_arr_append(dyn_int_arr_s *arr, int value);

bool dyn_int_arr_prepend(dyn_int_arr_s *arr, int value);

#endif
