#include <assert.h>
#include <stdio.h>

#include "dyn_stack.h"

void assert_dyn_stack()
{
    dyn_stack_s *s = dyn_stack_create();
    assert(s != NULL);
    printf("[OK] Stack created\n");

    int *v1 = malloc(sizeof(int));
    int *v2 = malloc(sizeof(int));
    int *v3 = malloc(sizeof(int));
    *v1 = 1;
    *v2 = 2;
    *v3 = 3;

    assert(dyn_stack_push(s, v1) == true);
    assert(dyn_stack_push(s, v2) == true);
    assert(dyn_stack_push(s, v3) == true);
    printf("[OK] Pushed 3 elements\n");

    int *peek = (int *)dyn_stack_peak(s);
    assert(*peek == 3);
    printf("[OK] Peeked value is 3 (last pushed)\n");

    assert(dyn_stack_pop(s) == true);
    peek = (int *)dyn_stack_peak(s);
    assert(*peek == 2);
    printf("[OK] Popped once, peek is now 2\n");

    assert(dyn_stack_pop(s) == true);
    peek = (int *)dyn_stack_peak(s);
    assert(*peek == 1);
    printf("[OK] Popped again, peek is now 1\n");

    assert(dyn_stack_pop(s) == true);
    assert(dyn_stack_peak(s) == NULL);
    printf("[OK] Popped last element, stack is now empty\n");

    dyn_stack_destroy(s);
    printf("[OK] Stack destroyed\n");
}

int main()
{
    assert_dyn_stack();

    return EXIT_SUCCESS;
}
