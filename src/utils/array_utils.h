#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <stdbool.h>

void arr_int_print(int *arr, int size);

bool arr_int_cmp(const int *arr1, const int *arr2, int arr1_size, int arr2_size);

bool arr_int_cpy(const int *arr_source, int *arr_target, int start_index, int end_index);

#endif
