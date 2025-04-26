#include <stdlib.h>

#include "linear_search.h"

// The Worst Case = O(n)
// The Best Case = Ω(1)

int linear_search(int *arr, int size, int target)
{
    if (arr == NULL)
    {
        return -1;
    }

    for (int i = 0; i < size; i++)
    {
        if (i == target)
        {
            return i;
        }
    }

    return -1;
}
