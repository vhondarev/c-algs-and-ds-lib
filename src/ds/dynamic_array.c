#include "dynamic_array.h"
#include <stdlib.h>
#include <string.h>

dyn_arr_s *dyn_arr_create()
{
    dyn_arr_s *arr = malloc(sizeof(dyn_arr_s));

    if (arr == NULL)
    {
        return NULL;
    }

    arr->data = NULL;
    arr->capacity = 0;
    arr->size = 0;

    return arr;
}

bool dyn_arr_init_mem(dyn_arr_s *arr)
{
    if (arr == NULL || arr->data != NULL)
    {
        return false;
    }

    arr->capacity = 2;
    arr->data = malloc(arr->capacity * sizeof(void *));

    if (arr->data == NULL)
    {
        return false;
    }

    return true;
}

int dyn_arr_realloc_mem(dyn_arr_s *arr)
{
    if (arr == NULL || arr->capacity == 0)
    {
        return -1;
    }

    bool should_decrease = (arr->capacity > 4 && arr->capacity > arr->size * 2);

    if (arr->size >= arr->capacity || should_decrease)
    {

        size_t nsize;
        if (should_decrease)
        {
            nsize = (size_t)(arr->capacity * 0.5);
        }
        else
        {
            nsize = arr->capacity * 2;
        }

        void **ndata = realloc(arr->data, nsize * sizeof(void *));

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

void dyn_arr_destroy(dyn_arr_s *arr)
{
    if (arr != NULL)
    {
        for (size_t i = 0; i < arr->size; i++)
        {
            free(arr->data[i]);
        }
        free(arr->data);
        arr->data = NULL;
        free(arr);
    }
}

bool dyn_arr_append(dyn_arr_s *arr, void *value)
{
    if (arr == NULL)
    {
        return false;
    }
    else if (arr->data == NULL)
    {
        if (!dyn_arr_init_mem(arr))
        {
            return false;
        }
    }

    if (dyn_arr_realloc_mem(arr) == -1)
    {
        return false;
    }

    arr->data[arr->size++] = value;

    return true;
}

bool dyn_arr_prepend(dyn_arr_s *arr, void *value)
{
    if (arr == NULL)
    {
        return false;
    }
    else if (arr->data == NULL)
    {
        if (!dyn_arr_init_mem(arr))
        {
            return false;
        }
    }
    if (dyn_arr_realloc_mem(arr) == -1)
    {
        return false;
    }

    for (size_t i = arr->size; i > 0; i--)
    {
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[0] = value;
    arr->size++;

    return true;
}

bool dyn_arr_remove_at(dyn_arr_s *arr, size_t index)
{
    if (arr == NULL || arr->data == NULL || arr->size <= index)
    {
        return false;
    }

    free(arr->data[index]);

    if (arr->size - 1 > index)
    {
        memmove(&arr->data[index], &arr->data[index + 1], (arr->size - index - 1) * sizeof(void *));
    }

    arr->size--;
    arr->data[arr->size] = NULL;

    dyn_arr_realloc_mem(arr);

    return true;
}

void *dyn_arr_get_at(dyn_arr_s *arr, size_t index)
{
    if (arr == NULL || arr->data == NULL || arr->size <= index)
    {
        return NULL;
    }

    return arr->data[index];
}
