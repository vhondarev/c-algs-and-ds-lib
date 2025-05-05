#include "selection_sort.h"

// The Best Case = Ω(n^2)
// The Worst Case = O(n^2)

bool selection_sort(int *arr, size_t size)
{
    if (arr == NULL || size < 0)
    {
        return false;
    }

    if (size != 0)
    {
        for (size_t i = 0; i < size - 1; i++)
        {
            size_t imin = i;

            for (size_t j = i + 1; j < size; j++)
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
    }

    return true;
}
