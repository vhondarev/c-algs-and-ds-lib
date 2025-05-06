#include "dyn_stack.h"

dyn_stack_s *dyn_stack_create()
{
    return dyn_arr_create();
}

bool dyn_stack_push(dyn_stack_s *s, void *value)
{
    return dyn_arr_append(s, value);
}

bool dyn_stack_pop(dyn_stack_s *s)
{
    if (s == NULL)
    {
        return false;
    }
    return dyn_arr_remove_at(s, s->size - 1);
}

void *dyn_stack_peak(dyn_stack_s *s)
{
    if (s == NULL)
    {
        return false;
    }
    return dyn_arr_get_at(s, s->size - 1);
};

void dyn_stack_destroy(dyn_stack_s *s)
{
    return dyn_arr_destroy(s);
}
