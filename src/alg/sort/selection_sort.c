#include <stdlib.h>

#include "selection_sort.h"

// The Best Case = Ω(n^2)
// The Worst Case = O(n^2)

bool selection_sort(int *arr, int size)
{
    if (arr == NULL)
    {
        return false;
    }

    for (int i = 0; i < size - 1; i++)
    {
        int imin = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[imin] > arr[j])
            {
                imin = j;
            }
        }

        if (imin != i)
        {
            int tmp = arr[i];
            arr[i] = arr[imin];
            arr[imin] = tmp;
        }
    }

    return true;
}
