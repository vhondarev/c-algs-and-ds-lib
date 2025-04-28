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

bool dyn_int_arr_init_mem(dyn_int_arr_s *arr)
{
    if (arr == NULL || arr->data != NULL)
    {
        return false;
    }
    else
    {
        arr->capacity = 2;
        arr->data = malloc(arr->capacity * sizeof(int));
        if (arr->data == NULL)
        {
            return false;
        }

        return true;
    }
}

int dyn_int_arr_realloc_mem(dyn_int_arr_s *arr)
{
    if (arr == NULL || arr->capacity == 0)
    {
        return -1;
    }
    else if (arr->size >= arr->capacity)
    {
        int nsize = arr->capacity * 2;
        int *ndata = realloc(arr->data, sizeof(int) * nsize);

        if (ndata == NULL)
        {
            return -1;
        }

        arr->capacity = nsize;
        arr->data = ndata;

        return 0;
    }
    return 1;
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
    else if (arr->data == NULL)
    {
        bool r = dyn_int_arr_init_mem(arr);
        if (!r)
        {
            return r;
        }
    }
    else
    {
        int r = dyn_int_arr_realloc_mem(arr);
        if (r == -1)
        {
            return false;
        }
    }

    arr->data[arr->size++] = value;

    return true;
}

bool dyn_int_arr_prepend(dyn_int_arr_s *arr, int value)
{
    if (arr == NULL)
    {
        return false;
    }
    else if (arr->data == NULL)
    {
        bool r = dyn_int_arr_init_mem(arr);
        if (!r)
        {
            return r;
        }
    }
    else
    {
        int r = dyn_int_arr_realloc_mem(arr);
        if (r == -1)
        {
            return false;
        }
    }

    if (arr->size == 0)
    {
        arr->data[arr->size++] = value;
    }
    else
    {
        for (int i = arr->size; i > 0; i--)
        {
            arr->data[i] = arr->data[i - 1];
        }
        arr->data[0] = value;
        arr->size++;
    }

    return true;
}
