#include "dyn_queue.h"

dyn_queue_s *dyn_queue_create()
{
    return dyn_arr_create();
}

bool dyn_queue_enqueue(dyn_queue_s *q, void *value)
{
    return dyn_arr_prepend(q, value);
}

bool dyn_queue_dequeue(dyn_queue_s *q)
{
    return dyn_arr_remove_at(q, 0);
}

void *dyn_queue_peak(dyn_queue_s *q)
{
    if (q == NULL)
    {
        return false;
    }
    return dyn_arr_get_at(q, q->size - 1);
}

void dyn_queue_destroy(dyn_queue_s *q)
{
    return dyn_arr_destroy(q);
}
