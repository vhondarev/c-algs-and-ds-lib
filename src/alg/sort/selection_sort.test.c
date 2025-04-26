#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../utils/array_utils.h"

#include "selection_sort.h"

int main()
{
    int arr_empty[] = {};
    int exp_arr_empty[] = {};
    int *arr_null = NULL;
    int *exp_arr_null = NULL;
    int arr1[] = {3, 5, 2, 4, 0, 1, 8, 7, 9, 6};
    int exp_arr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr2_one_item[] = {1};
    int exp_arr2_one_item[] = {1};
    size_t arr1_size = sizeof(arr1) / sizeof(arr1[0]);
    size_t exp_arr1_size = sizeof(exp_arr1) / sizeof(exp_arr1[0]);

    assert(selection_sort(arr_null, 0) == false);
    assert(arr_int_cmp(arr_null, exp_arr_null, 0, 0));
    printf("[OK] - NULL pointer (no errors)\n");

    assert(selection_sort(arr_empty, 0) == true);
    assert(arr_int_cmp(arr_empty, exp_arr_empty, 0, 0));
    printf("[OK] - Empty array (no errors)\n");

    assert(selection_sort(arr2_one_item, 1) == true);
    assert(arr2_one_item[0] == exp_arr2_one_item[0]);
    printf("[OK] - Sort array with one item\n");

    assert(selection_sort(arr1, arr1_size) == true);
    assert(arr_int_cmp(arr1, exp_arr1, arr1_size, exp_arr1_size));
    printf("[OK] - Sort array with many items\n");

    return EXIT_SUCCESS;
}
