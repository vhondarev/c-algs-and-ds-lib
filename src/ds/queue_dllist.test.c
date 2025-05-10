#include "queue_dllist.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_queue_create_destroy()
{
    queue_dllist_s *q = queue_dllist_create();
    assert(q != NULL);
    assert(q->head == NULL);
    assert(q->tail == NULL);
    assert(q->total == 0);
    queue_dllist_destroy(q);
    printf("[OK] - Queue create and destroy\n");
}

void test_queue_enqueue_dequeue()
{
    queue_dllist_s *q = queue_dllist_create();

    int *d1 = malloc(sizeof(int));
    int *d2 = malloc(sizeof(int));
    int *d3 = malloc(sizeof(int));
    *d1 = 1;
    *d2 = 2;
    *d3 = 3;

    queue_dllist_node_s *n1 = queue_dllist_create_node(d1);
    queue_dllist_node_s *n2 = queue_dllist_create_node(d2);
    queue_dllist_node_s *n3 = queue_dllist_create_node(d3);

    assert(queue_dllist_enqueue(q, n1) == true);
    assert(queue_dllist_enqueue(q, n2) == true);
    assert(queue_dllist_enqueue(q, n3) == true);
    assert(q->head == n1);
    assert(q->tail == n3);
    assert(q->total == 3);
    printf("[OK] - Peek after enqueue\n");

    assert(queue_dllist_dequeue(q) == true);
    assert(q->head == n2);
    assert(q->total == 2);
    printf("[OK] - Dequeued 1st item\n");

    assert(queue_dllist_dequeue(q) == true);
    assert(q->head == n3);
    assert(q->total == 1);
    printf("[OK] - Dequeued 2nd item\n");

    assert(queue_dllist_dequeue(q) == true);
    assert(q->head == NULL);
    assert(q->tail == NULL);
    assert(q->total == 0);
    assert(queue_dllist_peek(q) == NULL);
    printf("[OK] - Dequeued last item, queue empty\n");

    assert(queue_dllist_dequeue(q) == false);
    printf("[OK] - Dequeue on empty queue\n");

    queue_dllist_destroy(q);
    printf("[OK] - Queue enqueue and dequeue\n");
}

int main()
{
    test_queue_create_destroy();
    test_queue_enqueue_dequeue();

    return EXIT_SUCCESS;
}
