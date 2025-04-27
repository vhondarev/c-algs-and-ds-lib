#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "dynamic_array.h"

int main()
{
    dyn_int_arr_s *darr = dyn_int_arr_create();

    assert(darr != NULL);
    assert(darr->data == NULL);
    assert(darr->capacity == 0);
    assert(darr->size == 0);
    printf("[OK] - Created empty dynamic array\n");

    assert(dyn_int_arr_append(darr, 0) == true);
    assert(darr->data[0] == 0);
    assert(darr->capacity = 2);
    assert(darr->size == 1);
    printf("[OK] - Appended first element\n");

    assert(dyn_int_arr_append(darr, 1) == true);
    assert(darr->data[1] == 1);
    assert(darr->capacity = 2);
    assert(darr->size == 2);
    printf("[OK] - Appended second element (capacity not full)\n");

    assert(dyn_int_arr_append(darr, 2) == true);
    assert(darr->data[2] == 2);
    assert(darr->capacity = 4);
    assert(darr->size == 3);
    printf("[OK] - Appended third element (reallocation triggered)\n");

    assert(dyn_int_arr_append(NULL, 100) == false);
    printf("[OK] - Appending to NULL array returns false\n");

    assert(dyn_int_arr_destroy(darr) == true);
    printf("[OK] - Destroyed dynamic array\n");

    return EXIT_SUCCESS;
}
