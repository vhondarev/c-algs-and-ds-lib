#include <assert.h>
#include <stdio.h>

#include "dyn_queue.h"

void assert_dyn_queue()
{
    dyn_queue_s *q = dyn_queue_create();
    assert(q != NULL);
    printf("[OK] Queue created\n");

    int *v1 = malloc(sizeof(int));
    int *v2 = malloc(sizeof(int));
    int *v3 = malloc(sizeof(int));
    *v1 = 1;
    *v2 = 2;
    *v3 = 3;

    assert(dyn_queue_enqueue(q, v1) == true);
    assert(dyn_queue_enqueue(q, v2) == true);
    assert(dyn_queue_enqueue(q, v3) == true);
    assert(q->size == 3);
    assert(*(int *)q->data[0] == 3);
    assert(*(int *)q->data[1] == 2);
    assert(*(int *)q->data[2] == 1);
    printf("[OK] Enqueued 3 elements\n");

    int *peek = (int *)dyn_queue_peak(q);
    assert(*peek == 1);
    printf("[OK] Peeked value is 1\n");

    assert(dyn_queue_dequeue(q) == true);
    assert(q->size == 2);
    assert(*(int *)q->data[0] == 2);
    assert(*(int *)q->data[1] == 1);
    peek = (int *)dyn_queue_peak(q);
    assert(*peek == 1);
    printf("[OK] Dequeued once, peek is still 1, size reduced by 1, first element changed\n");

    assert(dyn_queue_dequeue(q) == true);
    assert(q->size == 1);
    assert(*(int *)q->data[0] == 1);
    peek = (int *)dyn_queue_peak(q);
    assert(*peek == 1);
    printf("[OK] Dequeued again, peek is still 1, size reduced by 1, first element changed\n");

    assert(dyn_queue_dequeue(q) == true);
    assert(q->size == 0);
    assert(dyn_queue_peak(q) == NULL);
    printf("[OK] Dequeued last element, queue is now empty\n");

    dyn_queue_destroy(q);
    printf("[OK] Queue destroyed\n");
}

int main()
{
    assert_dyn_queue();

    return EXIT_SUCCESS;
}
