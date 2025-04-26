#include <stdlib.h>

#include "merge_sort.h"

bool merge_sort(int *arr, int left, int right)
{
    if (arr == NULL)
    {
        return false;
    }

    if (left >= right - 1)
    {
        return true;
    }

    int mid = left + (right - left) / 2;
    int lsize = mid - left;
    int rsize = right - mid;

    int *larr = calloc(lsize, sizeof(int));
    int *rarr = calloc(rsize, sizeof(int));

    if (!larr || !rarr)
    {
        free(larr);
        free(rarr);
        return false;
    }

    arr_int_cpy(arr, larr, left, mid);
    arr_int_cpy(arr, rarr, mid, right);

    bool lsuccess = merge_sort(larr, 0, lsize);
    bool rsuccess = merge_sort(rarr, 0, rsize);

    if (!lsuccess || !rsuccess)
    {
        free(larr);
        free(rarr);
        return false;
    }

    int i = 0, j = 0, m = left;
    while (i < lsize && j < rsize)
    {
        if (larr[i] < rarr[j])
        {
            arr[m++] = larr[i++];
        }
        else
        {
            arr[m++] = rarr[j++];
        }
    }

    while (i < lsize)
    {
        arr[m++] = larr[i++];
    }

    while (j < rsize)
    {
        arr[m++] = rarr[j++];
    }

    free(larr);
    free(rarr);

    return true;
}
