#include <assert.h>
#include <stdio.h>

#include "queue_circ.h"

void assert_queue_null()
{
    assert(queue_circ_enqueue(NULL, NULL) == false);
    assert(queue_circ_dequeue(NULL) == false);
    assert(queue_circ_empty(NULL) == true);
    assert(queue_circ_full(NULL) == true);
    printf("[OK] - NULL pointer checks passed\n");
}

void assert_queue_basic()
{
    queue_circ_s *q = queue_circ_init(3);
    assert(q != NULL);
    printf("[OK] - Queue initialized\n");

    assert(queue_circ_empty(q));
    assert(queue_circ_full(q) == false);
    printf("[OK] - Queue is empty and not full\n");

    int *a = malloc(sizeof(int));
    *a = 1;
    int *b = malloc(sizeof(int));
    *b = 2;
    int *c = malloc(sizeof(int));
    *c = 3;
    int *d = malloc(sizeof(int));
    *d = 4;

    assert(queue_circ_enqueue(q, a));
    assert(queue_circ_empty(q) == false);
    assert(queue_circ_dequeue(q));
    assert(queue_circ_empty(q) == true);
    printf("[OK] - Enqueue and dequeue one element\n");

    assert(queue_circ_enqueue(q, a));
    assert(q->data[q->back] == a);
    assert(q->data[q->front] == a);
    assert(queue_circ_enqueue(q, b));
    assert(q->data[q->back] == b);
    assert(q->data[q->front] == a);
    assert(queue_circ_enqueue(q, c));
    assert(q->data[q->back] == c);
    assert(q->data[q->front] == a);
    assert(queue_circ_full(q));
    printf("[OK] - Enqueued 3 elements, queue is full\n");

    assert(queue_circ_enqueue(q, d) == false);
    printf("[OK] - Rejected enqueue when queue is full\n");

    assert(queue_circ_dequeue(q));
    assert(q->data[q->back] == c);
    assert(q->data[q->front] == b);
    assert(queue_circ_dequeue(q));
    assert(q->data[q->back] == c);
    assert(q->data[q->front] == c);
    assert(queue_circ_dequeue(q));
    assert(queue_circ_empty(q));
    assert(queue_circ_dequeue(q) == false);
    printf("[OK] - Dequeued all elements, queue is empty\n");

    free(a);
    free(b);
    free(c);
    free(d);

    queue_circ_destroy(q);
    printf("[OK] - Queue destroyed successfully\n");
}

int main()
{
    assert_queue_null();
    assert_queue_basic();

    return EXIT_SUCCESS;
}
