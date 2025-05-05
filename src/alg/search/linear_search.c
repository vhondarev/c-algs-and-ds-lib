#include <stdlib.h>

#include "linear_search.h"

// The Best Case = Ω(1)
// The Worst Case = O(n)

int linear_search(int *arr, ssize_t size, int target)
{
    if (arr == NULL || size < 0)
    {
        return -1;
    }

    for (size_t i = 0; i < size; i++)
    {
        if (i == target)
        {
            return i;
        }
    }

    return -1;
}
