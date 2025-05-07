#include <assert.h>
#include <stdio.h>

#include "stack_dyarr.h"

void assert_stack_dyarr()
{
    stack_dyarr_s *s = stack_dyarr_create();
    assert(s != NULL);
    printf("[OK] Stack created\n");

    int *v1 = malloc(sizeof(int));
    int *v2 = malloc(sizeof(int));
    int *v3 = malloc(sizeof(int));
    *v1 = 1;
    *v2 = 2;
    *v3 = 3;

    assert(stack_dyarr_push(s, v1) == true);
    assert(stack_dyarr_push(s, v2) == true);
    assert(stack_dyarr_push(s, v3) == true);
    printf("[OK] Pushed 3 elements\n");

    int *peek = (int *)stack_dyarr_peak(s);
    assert(*peek == 3);
    printf("[OK] Peeked value is 3 (last pushed)\n");

    assert(stack_dyarr_pop(s) == true);
    peek = (int *)stack_dyarr_peak(s);
    assert(*peek == 2);
    printf("[OK] Popped once, peek is now 2\n");

    assert(stack_dyarr_pop(s) == true);
    peek = (int *)stack_dyarr_peak(s);
    assert(*peek == 1);
    printf("[OK] Popped again, peek is now 1\n");

    assert(stack_dyarr_pop(s) == true);
    assert(stack_dyarr_peak(s) == NULL);
    printf("[OK] Popped last element, stack is now empty\n");

    stack_dyarr_destroy(s);
    printf("[OK] Stack destroyed\n");
}

int main()
{
    assert_stack_dyarr();

    return EXIT_SUCCESS;
}
