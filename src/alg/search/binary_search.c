#include "binary_search.h"

// The Best Case = Ω(1)
// The Worst Case = O(log n)

int binary_search(const int arr[], ssize_t start, ssize_t end, int target)
{
    if (arr == NULL)
    {
        return -1;
    }

    while (start <= end)
    {
        ssize_t mid = start + ((end - start) / 2);

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}
