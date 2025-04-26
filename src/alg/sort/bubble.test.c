#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../utils/array_utils.h"

#include "bubble.h"

int main(int argc, char *argv[])
{
    int arr_empty[] = {};
    int exp_arr_empty[] = {};
    int *arr_null = NULL;
    int *exp_arr_null = NULL;
    int arr1[] = {3, 5, 2, 4, 0, 1, 8, 7, 9, 6};
    int exp_arr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t arr1_size = sizeof(arr1) / sizeof(arr1[0]);
    size_t exp_arr1_size = sizeof(exp_arr1) / sizeof(exp_arr1[0]);

    printf("[OK] - NULL pointer (no errrors)\n");
    bubble_sort(arr_null, 0);
    assert(arr_int_cmp(arr_null, exp_arr_null, 0, 0));

    printf("[OK] - Empty array (no errors)\n");
    bubble_sort(arr_empty, 0);
    assert(arr_int_cmp(arr_empty, exp_arr_empty, 0, 0));

    printf("[OK] - NULL pointer\n");
    bubble_sort(arr1, arr1_size);
    assert(arr_int_cmp(arr1, exp_arr1, arr1_size, exp_arr1_size));

    return EXIT_SUCCESS;
}
