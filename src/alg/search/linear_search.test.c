#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "linear_search.h"

int main()
{
    int arr_empty[] = {};
    int *arr_null = NULL;
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("[OK] - NULL pointer (target does not exist)\n");
    assert(linear_search(arr_null, 1, 7) == -1);

    printf("[OK] - Target exists in the array\n");
    assert(linear_search(arr, arr_size, 7) == 7);

    printf("[OK] - Target does not exist in the array (greater than max)\n");
    assert(linear_search(arr, arr_size, 10) == -1);

    printf("[OK] - Target does not exist in the array (less than min)\n");
    assert(linear_search(arr, arr_size, -1) == -1);

    printf("[OK] - Empty array (target does not exist)\n");
    assert(linear_search(arr_empty, 0, 0) == -1);

    return EXIT_SUCCESS;
}
