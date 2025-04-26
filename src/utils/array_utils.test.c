#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_utils.h"

int main()
{
    int arr1_empty[] = {};
    int arr2_empty[] = {};
    int *arr1_null = NULL;
    int *arr2_null = NULL;
    int arr1[] = {1, 2};
    int arr2[] = {1, 2};
    int arr3[] = {1, 1};
    int arr4[] = {0, 0, 0};
    size_t arr1_size = sizeof(arr1) / sizeof(arr1[0]);
    size_t arr2_size = sizeof(arr2) / sizeof(arr2[0]);
    size_t arr3_size = sizeof(arr3) / sizeof(arr3[0]);
    size_t arr4_size = sizeof(arr4) / sizeof(arr4[0]);

    printf("[OK] - NULL pointer\n");
    assert(arr_int_cmp(arr1_empty, arr1_null, 0, 0) == false);
    assert(arr_int_cmp(arr1_null, arr1_empty, 0, 0) == false);
    assert(arr_int_cmp(arr1_null, arr2_null, 0, 0) == true);

    printf("[OK] - Empty arrays are equal\n");
    assert(arr_int_cmp(arr1_empty, arr2_empty, 0, 0) == true);

    printf("[OK] - Non empty arrays are equal\n");
    assert(arr_int_cmp(arr1, arr2, arr1_size, arr2_size) == true);

    printf("[OK] - Arrays are not equal\n");
    assert(arr_int_cmp(arr1, arr3, arr1_size, arr3_size) == false);

    printf("[OK] - Different array size\n");
    assert(arr_int_cmp(arr1_empty, arr4, 0, arr4_size) == false);

    return EXIT_SUCCESS;
}
