#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    void **data;
    size_t size;
    size_t capacity;
} dyn_arr_s;

dyn_arr_s *dyn_arr_create();

bool dyn_arr_init_mem(dyn_arr_s *arr);

int dyn_arr_realloc_mem(dyn_arr_s *arr);

void dyn_arr_destroy(dyn_arr_s *arr);

bool dyn_arr_append(dyn_arr_s *arr, void *value);

bool dyn_arr_prepend(dyn_arr_s *arr, void *value);

bool dyn_arr_remove_at(dyn_arr_s *arr, int index);

void *dyn_arr_get_at(dyn_arr_s *arr, int index);

#endif
