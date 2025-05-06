#include <stdio.h>
#include <stdlib.h>

#include "array_utils.h"

void arr_int_print(int *arr, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Index %i has value %i\n", i, arr[i]);
    }
}

bool arr_int_cmp(const int *arr1, const int *arr2, int arr1_size, int arr2_size)
{
    if (arr1_size != arr2_size || (arr1 == NULL && arr2 != NULL) || (arr1 != NULL && arr2 == NULL))
    {
        return false;
    }
    else if (arr1 == NULL && arr2 == NULL)
    {
        return true;
    }

    for (int i = 0; i < arr1_size; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return false;
        }
    }

    return true;
}

// UNSAFE: This function copies a portion of arr_source to arr_target WITHOUT bounds checking on
// arr_source or arr_target.
bool arr_int_cpy(const int *arr_source, int *arr_target, int start_index, int end_index)
{
    if (arr_source == NULL || arr_target == NULL || start_index < 0 || start_index > end_index)
    {
        return false;
    }

    for (int i = 0; i < end_index - start_index; i++)
    {
        arr_target[i] = arr_source[start_index + i];
    }

    return true;
}
