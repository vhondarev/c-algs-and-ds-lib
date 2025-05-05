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
    printf("[OK] - Do not realloc when capacity is 0\n");

    assert(dyn_arr_init_mem(darr) == true);
    assert(darr->data != NULL);
    assert(darr->size == 0);
    assert(darr->capacity == 2);
    printf("[OK] - Allocated memory for dynamic array\n");

    assert(dyn_arr_realloc_mem(darr) == 1);
    printf("[OK] - Skipped realloc when size/capacity did not require it\n");

    darr->size = 2;
    assert(dyn_arr_realloc_mem(darr) == 0);
    assert(darr->capacity > 2);
    printf("[OK] - Reallocation triggered for growth\n");

    size_t old_capacity;

    darr->size = 6;
    assert(dyn_arr_realloc_mem(darr) == 0);
    old_capacity = darr->capacity;
    darr->size = 2;
    assert(dyn_arr_realloc_mem(darr) == 0);
    assert(darr->capacity < old_capacity);
    printf("[OK] - Reallocation triggered for shrink\n");

    old_capacity = darr->capacity;
    darr->size = 1;
    assert(dyn_arr_realloc_mem(darr) == 1);
    assert(darr->capacity == old_capacity);
    printf("[OK] - Skipped realloc when capacity less then 4\n");

    dyn_arr_destroy(darr);
    printf("[OK] - Destroyed dynamic array\n");
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
    assert(darr->capacity >= 2);
    assert(darr->size == 1);
    printf("[OK] - Appended first element to empty array\n");

    assert(dyn_arr_append(darr, b) == true);
    assert(*(int *)darr->data[0] == 0);
    assert(*(int *)darr->data[1] == 1);
    assert(darr->size == 2);
    printf("[OK] - Appended second element\n");

    assert(dyn_arr_append(darr, c) == true);
    assert(*(int *)darr->data[2] == 2);
    assert(darr->size == 3);
    assert(darr->capacity >= 3);
    printf("[OK] - Appended third element (triggered growth realloc)\n");

    assert(dyn_arr_append(NULL, a) == false);
    printf("[OK] - Appending to NULL array returns false\n");

    dyn_arr_destroy(darr);
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
    printf("[OK] - Prepended first element\n");

    assert(dyn_arr_prepend(darr, b) == true);
    assert(*(int *)darr->data[0] == 1);
    assert(*(int *)darr->data[1] == 0);
    assert(darr->size == 2);
    printf("[OK] - Prepended second element\n");

    assert(dyn_arr_prepend(darr, c) == true);
    assert(*(int *)darr->data[0] == 2);
    assert(*(int *)darr->data[1] == 1);
    assert(*(int *)darr->data[2] == 0);
    assert(darr->size == 3);
    assert(darr->capacity >= 3);
    printf("[OK] - Prepended third element (triggered growth realloc)\n");

    assert(dyn_arr_prepend(NULL, a) == false);
    printf("[OK] - Prepend to NULL array returns false\n");

    dyn_arr_destroy(darr);
    printf("[OK] - Destroyed dynamic array\n");
}

void assert_dyn_arr_remove_at()
{
    dyn_arr_s *darr = dyn_arr_create();

    int *a = malloc(sizeof(int));
    *a = 0;
    int *b = malloc(sizeof(int));
    *b = 1;
    int *c = malloc(sizeof(int));
    *c = 2;
    int *d = malloc(sizeof(int));
    *d = 3;
    int *e = malloc(sizeof(int));
    *e = 4;

    assert(dyn_arr_append(darr, a) == true);
    assert(dyn_arr_append(darr, b) == true);
    assert(dyn_arr_append(darr, c) == true);
    assert(darr->size == 3);

    assert(dyn_arr_remove_at(darr, 0) == true);
    assert(darr->size == 2);
    assert(*(int *)darr->data[0] == 1);
    assert(*(int *)darr->data[1] == 2);
    printf("[OK] - Removed first element\n");

    assert(dyn_arr_remove_at(darr, 1) == true);
    assert(darr->size == 1);
    assert(*(int *)darr->data[0] == 1);
    printf("[OK] - Removed last element\n");

    assert(dyn_arr_append(darr, d) == true);
    assert(dyn_arr_append(darr, e) == true);
    assert(dyn_arr_remove_at(darr, 1) == true);
    assert(darr->size == 2);
    assert(*(int *)darr->data[0] == 1);
    assert(*(int *)darr->data[1] == 4);
    printf("[OK] - Removed middle element\n");

    assert(dyn_arr_remove_at(darr, 5) == false);
    printf("[OK] - Remove at invalid index returns false\n");

    dyn_arr_s *empty_darr = dyn_arr_create();
    assert(dyn_arr_remove_at(empty_darr, 0) == false);
    printf("[OK] - Remove from empty array returns false\n");

    dyn_arr_destroy(darr);
    dyn_arr_destroy(empty_darr);
    printf("[OK] - Destroyed dynamic array\n");
}

void assert_dyn_arr_get_at()
{
    dyn_arr_s *darr = dyn_arr_create();

    int *a = malloc(sizeof(int));
    *a = 0;
    int *b = malloc(sizeof(int));
    *b = 1;
    int *c = malloc(sizeof(int));
    *c = 2;

    assert(dyn_arr_append(darr, a) == true);
    assert(dyn_arr_append(darr, b) == true);
    assert(dyn_arr_append(darr, c) == true);

    int *value = (int *)dyn_arr_get_at(darr, 0);
    assert(value != NULL);
    assert(*value == 0);
    printf("[OK] - Get element at index 0: %d\n", *value);

    value = (int *)dyn_arr_get_at(darr, 1);
    assert(value != NULL);
    assert(*value == 1);
    printf("[OK] - Get element at index 1: %d\n", *value);

    value = (int *)dyn_arr_get_at(darr, 2);
    assert(value != NULL);
    assert(*value == 2);
    printf("[OK] - Get element at index 2: %d\n", *value);

    value = (int *)dyn_arr_get_at(darr, 3);
    assert(value == NULL);
    printf("[OK] - Get element at invalid index 3 returns NULL\n");

    value = (int *)dyn_arr_get_at(darr, 5);
    assert(value == NULL);
    printf("[OK] - Get element at invalid index 5 returns NULL\n");

    dyn_arr_s *empty_darr = dyn_arr_create();
    value = (int *)dyn_arr_get_at(empty_darr, 0);
    assert(value == NULL);
    printf("[OK] - Get element from empty array returns NULL\n");

    dyn_arr_destroy(darr);
    dyn_arr_destroy(empty_darr);
    printf("[OK] - Destroyed dynamic array\n");
}

int main()
{
    assert_dyn_arr_init();
    assert_dyn_mem();
    assert_dyn_arr_append();
    assert_dyn_arr_prepend();
    assert_dyn_arr_remove_at();
    assert_dyn_arr_get_at();

    return EXIT_SUCCESS;
}
