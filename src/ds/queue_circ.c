#include "queue_circ.h"

queue_circ_s *queue_circ_init(size_t length)
{
    if (length < 2)
    {
        return NULL;
    }

    queue_circ_s *q = malloc(sizeof(queue_circ_s));

    if (q == NULL)
        return NULL;

    q->data = malloc(sizeof(void *) * length);

    if (q->data == NULL)
    {
        free(q);
        return NULL;
    }

    q->front = q->back = -1;
    q->length = length;

    return q;
}

void queue_circ_destroy(queue_circ_s *q)
{
    if (q != NULL)
    {
        while (!queue_circ_empty(q))
        {
            queue_circ_dequeue(q);
        }

        free(q->data);
        free(q);
    }
}

bool queue_circ_empty(queue_circ_s *q)
{
    if (q != NULL)
    {
        return q->front == -1;
    }
    return true;
}

bool queue_circ_full(queue_circ_s *q)
{
    if (q != NULL)
    {
        return (q->back + 1) % q->length == q->front;
    }
    return true;
}

bool queue_circ_enqueue(queue_circ_s *q, void *data)
{
    if (q == NULL || queue_circ_full(q))
    {
        return false;
    }

    if (queue_circ_empty(q))
    {
        q->front = q->back = 0;
    }
    else
    {
        q->back = (q->back + 1) % q->length;
    }

    q->data[q->back] = data;

    return true;
}

bool queue_circ_dequeue(queue_circ_s *q)
{
    if (q != NULL)
    {
        if (queue_circ_empty(q))
        {
            return false;
        }

        if (q->front == q->back)
        {
            q->front = q->back = -1;
        }
        else
        {
            q->front = (q->front + 1) % q->length;
        }

        return true;
    }

    return false;
}
