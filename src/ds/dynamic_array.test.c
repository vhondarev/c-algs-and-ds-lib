#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "dynamic_array.h"

void assert_dyn_arr_init()
{
    dyn_arr_s *darr = dyn_arr_create();
    assert(darr != NULL);
    assert(darr->data == NULL);
    assert(darr->size == 0);
    assert(darr->capacity == 0);
    printf("[OK] - Created empty dynamic array\n");

    dyn_arr_destroy(darr);
}

void assert_dyn_mem()
{
    dyn_arr_s *darr = dyn_arr_create();

    assert(dyn_arr_realloc_mem(darr) == -1);
    printf("[OK] - Do not realloc when capacity 0\n");

    dyn_arr_init_mem(darr);
    assert(darr != NULL);
    assert(darr->data != NULL);
    assert(darr->size == 0);
    assert(darr->capacity == 2);
    printf("[OK] - Allocate memory for the first element\n");

    assert(dyn_arr_realloc_mem(darr) == 1);
    printf("[OK] - Skip memory reallocation for a new element\n");

    darr->size = 2;
    assert(dyn_arr_realloc_mem(darr) == 0);
    printf("[OK] - Reallocate memory for a new element\n");

    dyn_arr_destroy(darr);
}

void assert_dyn_arr_append()
{
    dyn_arr_s *darr = dyn_arr_create();

    int *a = malloc(sizeof(int));
    *a = 0;
    int *b = malloc(sizeof(int));
    *b = 1;
    int *c = malloc(sizeof(int));
    *c = 2;

    assert(dyn_arr_append(darr, a) == true);
    assert(*(int *)darr->data[0] == 0);
    assert(darr->capacity == 2);
    assert(darr->size == 1);
    printf("[OK] - Appended first element to empty array\n");

    assert(dyn_arr_append(darr, b) == true);
    assert(*(int *)darr->data[0] == 0);
    assert(*(int *)darr->data[1] == 1);
    assert(darr->size == 2);
    assert(darr->capacity == 2);
    printf("[OK] - Appended second element (capacity not full)\n");

    assert(dyn_arr_append(darr, c) == true);
    assert(*(int *)darr->data[0] == 0);
    assert(*(int *)darr->data[1] == 1);
    assert(*(int *)darr->data[2] == 2);
    assert(darr->size == 3);
    assert(darr->capacity == 4);
    printf("[OK] - Appended third element (reallocation triggered)\n");

    assert(dyn_arr_append(NULL, a) == false);
    printf("[OK] - Appending to NULL array returns false\n");

    dyn_arr_destroy(darr);
    free(a);
    free(b);
    free(c);

    printf("[OK] - Destroyed dynamic array\n");
}

void assert_dyn_arr_prepend()
{
    dyn_arr_s *darr = dyn_arr_create();

    int *a = malloc(sizeof(int));
    *a = 0;
    int *b = malloc(sizeof(int));
    *b = 1;
    int *c = malloc(sizeof(int));
    *c = 2;

    assert(dyn_arr_prepend(darr, a) == true);
    assert(*(int *)darr->data[0] == 0);
    assert(darr->size == 1);
    assert(darr->capacity == 2);
    printf("[OK] - Prepended first element to empty array\n");

    assert(dyn_arr_prepend(darr, b) == true);
    assert(*(int *)darr->data[0] == 1);
    assert(*(int *)darr->data[1] == 0);
    assert(darr->size == 2);
    printf("[OK] - Prepended element to non-empty array\n");

    assert(dyn_arr_prepend(darr, c) == true);
    assert(*(int *)darr->data[0] == 2);
    assert(*(int *)darr->data[1] == 1);
    assert(*(int *)darr->data[2] == 0);
    assert(darr->size == 3);
    assert(darr->capacity == 4);
    printf("[OK] - Prepended third element (reallocation triggered)\n");

    assert(dyn_arr_prepend(NULL, a) == false);
    printf("[OK] - Prepend to NULL array returns false\n");

    dyn_arr_destroy(darr);
    free(a);
    free(b);
    free(c);

    printf("[OK] - Destroyed dynamic array\n");
}

int main()
{
    assert_dyn_arr_init();
    assert_dyn_mem();
    assert_dyn_arr_append();
    assert_dyn_arr_prepend();

    return EXIT_SUCCESS;
}
