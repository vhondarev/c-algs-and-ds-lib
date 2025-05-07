#include "queue_dyarr.h"

queue_dyarr_s *queue_dyarr_create()
{
    return dyn_arr_create();
}

bool queue_dyarr_enqueue(queue_dyarr_s *q, void *data)
{
    return dyn_arr_prepend(q, data);
}

bool queue_dyarr_dequeue(queue_dyarr_s *q)
{
    return dyn_arr_remove_at(q, 0);
}

void *queue_dyarr_peak(queue_dyarr_s *q)
{
    if (q == NULL)
    {
        return false;
    }
    return dyn_arr_get_at(q, q->size - 1);
}

void queue_dyarr_destroy(queue_dyarr_s *q)
{
    return dyn_arr_destroy(q);
}
