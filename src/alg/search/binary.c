#include <stdlib.h>

// The Worst Case = O(log n)
// The Best Case = Ω(1)

int binarySearch(const int arr[], int start, int end, int target)
{
    if (arr == NULL)
    {
        return -1;
    }

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] < target)
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
