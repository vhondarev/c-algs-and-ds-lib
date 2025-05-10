#include "queue_dllist.h"

queue_dllist_node_s *queue_dllist_create_node(void *data)
{
    return dllist_create_node(data);
}

void queue_dllist_destroy_node(queue_dllist_node_s *node)
{
    dllist_destroy_node(node);
}

queue_dllist_s *queue_dllist_create()
{
    queue_dllist_s *q = malloc(sizeof(queue_dllist_s));
    if (q == NULL)
    {
        return NULL;
    }
    q->head = NULL;
    q->tail = NULL;
    q->total = 0;

    return q;
}

void queue_dllist_destroy(queue_dllist_s *queue)
{
    return dllist_destroy((queue_dllist_s *)queue);
}

bool queue_dllist_enqueue(queue_dllist_s *queue, queue_dllist_node_s *node)
{
    return dllist_append((queue_dllist_s *)queue, (queue_dllist_node_s *)node);
}

bool queue_dllist_dequeue(queue_dllist_s *queue)
{
    return dllist_delete_at((queue_dllist_s *)queue, 0);
}

queue_dllist_node_s *queue_dllist_peek(queue_dllist_s *queue)
{
    return dllist_get_node_at((queue_dllist_s *)queue, 0);
}
