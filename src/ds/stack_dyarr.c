#include "stack_dyarr.h"

stack_dyarr_s *stack_dyarr_create()
{
    return darr_create();
}

bool stack_dyarr_push(stack_dyarr_s *s, void *data)
{
    return darr_append(s, data);
}

bool stack_dyarr_pop(stack_dyarr_s *s)
{
    if (s == NULL)
    {
        return false;
    }
    return darr_remove_at(s, s->size - 1);
}

void *stack_dyarr_peak(stack_dyarr_s *s)
{
    if (s == NULL)
    {
        return false;
    }
    return darr_get_at(s, s->size - 1);
};

void stack_dyarr_destroy(stack_dyarr_s *s)
{
    return darr_destroy(s);
}
