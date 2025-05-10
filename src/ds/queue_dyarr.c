#include "queue_dyarr.h"

queue_dyarr_s *queue_dyarr_create()
{
    return darr_create();
}

void queue_dyarr_destroy(queue_dyarr_s *q)
{
    return darr_destroy(q);
}

bool queue_dyarr_enqueue(queue_dyarr_s *q, void *data)
{
    return darr_append(q, data);
}

bool queue_dyarr_dequeue(queue_dyarr_s *q)
{
    return darr_remove_at(q, 0);
}

void *queue_dyarr_peak(queue_dyarr_s *q)
{
    if (q == NULL)
    {
        return false;
    }

    return darr_get_at(q, 0);
}
