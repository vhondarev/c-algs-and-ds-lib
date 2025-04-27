#include <stdio.h>

#include "bubble_sort.h"

// The Best Case = Ω(n)
// The Worst Case = O(n^2)

bool bubble_sort(int *arr, int size)
{
    if (arr == NULL)
    {
        return false;
    }

    for (int i = 0; i < size - 1; i++)
    {
        int swapped = 0;

        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        if (swapped == 0)
        {
            return true;
        }
    }

    return true;
}
