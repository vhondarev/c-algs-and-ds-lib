#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    void **data;
    size_t size;
    size_t capacity;
} darr_s;

darr_s *darr_create();

bool darr_init_mem(darr_s *arr);

int darr_realloc_mem(darr_s *arr);

void darr_destroy(darr_s *arr);

bool darr_append(darr_s *arr, void *value);

bool darr_prepend(darr_s *arr, void *value);

bool darr_remove_at(darr_s *arr, int index);

void *darr_get_at(darr_s *arr, int index);

#endif
