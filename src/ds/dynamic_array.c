#include "dynamic_array.h"
#include <stdlib.h>
#include <string.h>

darr_s *darr_create()
{
    darr_s *arr = malloc(sizeof(darr_s));

    if (arr == NULL)
    {
        return NULL;
    }

    arr->data = NULL;
    arr->capacity = 0;
    arr->size = 0;

    return arr;
}

bool darr_init_mem(darr_s *arr)
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

int darr_realloc_mem(darr_s *arr)
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

void darr_destroy(darr_s *arr)
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

bool darr_append(darr_s *arr, void *value)
{
    if (arr == NULL)
    {
        return false;
    }
    else if (arr->data == NULL)
    {
        if (!darr_init_mem(arr))
        {
            return false;
        }
    }

    if (darr_realloc_mem(arr) == -1)
    {
        return false;
    }

    arr->data[arr->size++] = value;

    return true;
}

bool darr_prepend(darr_s *arr, void *value)
{
    if (arr == NULL)
    {
        return false;
    }
    else if (arr->data == NULL)
    {
        if (!darr_init_mem(arr))
        {
            return false;
        }
    }

    if (darr_realloc_mem(arr) == -1)
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

bool darr_remove_at(darr_s *arr, int index)
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

    darr_realloc_mem(arr);

    return true;
}

void *darr_get_at(darr_s *arr, int index)
{
    if (arr == NULL || arr->data == NULL || arr->size <= index)
    {
        return NULL;
    }

    return arr->data[index];
}
