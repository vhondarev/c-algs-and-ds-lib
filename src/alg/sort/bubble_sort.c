#include "bubble_sort.h"

// The Best Case = Ω(n)
// The Worst Case = O(n^2)

bool bubble_sort(int *arr, size_t size)
{
    if (arr == NULL || size < 0)
    {
        return false;
    }

    if (size != 0)
    {

        for (size_t i = 0; i < size - 1; i++)
        {
            int swapped = 0;

            for (size_t j = 0; j < size - i - 1; j++)
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
    }

    return true;
}
