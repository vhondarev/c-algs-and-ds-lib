#include "stack_dyarr.h"

stack_dyarr_s *stack_dyarr_create()
{
    return dyn_arr_create();
}

bool stack_dyarr_push(stack_dyarr_s *s, void *data)
{
    return dyn_arr_append(s, data);
}

bool stack_dyarr_pop(stack_dyarr_s *s)
{
    if (s == NULL)
    {
        return false;
    }
    return dyn_arr_remove_at(s, s->size - 1);
}

void *stack_dyarr_peak(stack_dyarr_s *s)
{
    if (s == NULL)
    {
        return false;
    }
    return dyn_arr_get_at(s, s->size - 1);
};

void stack_dyarr_destroy(stack_dyarr_s *s)
{
    return dyn_arr_destroy(s);
}
