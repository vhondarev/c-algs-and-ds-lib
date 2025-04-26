#include <stdlib.h>

#include "array_utils.h"

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
