#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "dynamic_array.h"

void assert_dyn_int_arr_init()
{
    dyn_int_arr_s *darr = dyn_int_arr_create();
    assert(darr != NULL);
    assert(darr->data == NULL);
    assert(darr->size == 0);
    assert(darr->capacity == 0);
    printf("[OK] - Created empty dynamic array\n");
}

void assert_dyn_int_mem()
{
    dyn_int_arr_s *darr = dyn_int_arr_create();

    assert(dyn_int_arr_realloc_mem(darr) == -1);
    printf("[OK] - Do not realloc when capacity 0\n");

    dyn_int_arr_init_mem(darr);
    assert(darr != NULL);
    assert(darr->data != NULL);
    assert(darr->size == 0);
    assert(darr->capacity == 2);
    printf("[OK] - Allocate memory for the first element\n");

    assert(dyn_int_arr_realloc_mem(darr) == 1);
    printf("[OK] - Skip memory reallocation for a new element\n");

    darr->size = 2;
    assert(dyn_int_arr_realloc_mem(darr) == 0);
    printf("[O] - Reallocate memory for a new element\n");
}

void assert_dyn_int_arr_append()
{
    dyn_int_arr_s *darr = dyn_int_arr_create();

    assert(dyn_int_arr_append(darr, 0) == true);
    assert(darr->data[0] == 0);
    assert(darr->capacity == 2);
    assert(darr->size == 1);
    printf("[OK] - Appended first element empty array\n");

    assert(dyn_int_arr_append(darr, 1) == true);
    assert(darr->data[0] == 0);
    assert(darr->data[1] == 1);
    assert(darr->size == 2);
    assert(darr->capacity == 2);
    printf("[OK] - Appended second element (capacity not full)\n");

    assert(dyn_int_arr_append(darr, 2) == true);
    assert(darr->data[0] == 0);
    assert(darr->data[1] == 1);
    assert(darr->data[2] == 2);
    assert(darr->size == 3);
    assert(darr->capacity == 4);
    printf("[OK] - Appended third element(reallocation triggered)\n");

    assert(dyn_int_arr_append(NULL, 100) == false);
    printf("[OK] - Appending to NULL array returns false\n");

    assert(dyn_int_arr_destroy(darr) == true);
    printf("[OK] - Destroyed dynamic array\n");
}

void assert_dyn_int_arr_prepend()
{
    dyn_int_arr_s *darr = dyn_int_arr_create();

    assert(dyn_int_arr_prepend(darr, 0) == true);
    assert(darr->data[0] == 0);
    assert(darr->size == 1);
    assert(darr->capacity == 2);
    printf("[OK] - Prepend first element to empy array\n");

    assert(dyn_int_arr_prepend(darr, 1) == true);
    assert(darr->data[0] == 1);
    assert(darr->data[1] == 0);
    assert(darr->size == 2);
    assert(darr->capacity == 2);
    printf("[OK] - Prepend item to element array (capacity not full)\n");

    assert(dyn_int_arr_prepend(darr, 2) == true);
    assert(darr->data[0] == 2);
    assert(darr->data[1] == 1);
    assert(darr->data[2] == 0);
    assert(darr->size == 3);
    assert(darr->capacity == 4);
    printf("[OK] - Appended third element(reallocation triggered)\n");

    assert(dyn_int_arr_prepend(NULL, 100) == false);
    printf("[OK] - Prepend to NULL array returns false\n");

    assert(dyn_int_arr_destroy(darr) == true);
    printf("[OK] - Destroyed dynamic array\n");
}

int main()
{
    assert_dyn_int_arr_init();
    assert_dyn_int_arr_append();
    assert_dyn_int_arr_prepend();

    return EXIT_SUCCESS;
}
