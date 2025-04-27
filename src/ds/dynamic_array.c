#include "dynamic_array.h"
#include <stdlib.h>

dyn_int_arr_s *dyn_int_arr_create()
{
    dyn_int_arr_s *arr = malloc(sizeof(dyn_int_arr_s));
    if (arr == NULL)
    {
        return NULL;
    }

    arr->data = NULL;
    arr->capacity = 0;
    arr->size = 0;

    return arr;
}

bool dyn_int_arr_destroy(dyn_int_arr_s *arr)
{
    if (arr != NULL)
    {
        free(arr->data);
        free(arr);
        return true;
    }

    return false;
}

bool dyn_int_arr_append(dyn_int_arr_s *arr, int value)
{
    if (arr == NULL)
    {
        return false;
    }

    if (arr->data == NULL)
    {
        arr->capacity = 2;
        arr->data = malloc(arr->capacity * sizeof(int));
        if (arr->data == NULL)
        {
            return false;
        }
    }
    else
    {
        if (arr->size >= arr->capacity)
        {
            int nsize = arr->capacity * 2;
            int *ndata = realloc(arr->data, sizeof(int) * nsize);

            if (ndata == NULL)
            {
                return false;
            }

            arr->capacity = nsize;
            arr->data = ndata;
        }
    }

    arr->data[arr->size++] = value;

    return true;
}
