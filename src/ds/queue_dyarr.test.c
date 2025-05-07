#include <assert.h>
#include <stdio.h>

#include "queue_dyarr.h"

void assert_queue_dyarr()
{
    queue_dyarr_s *q = queue_dyarr_create();
    assert(q != NULL);
    printf("[OK] Queue created\n");

    int *v1 = malloc(sizeof(int));
    int *v2 = malloc(sizeof(int));
    int *v3 = malloc(sizeof(int));
    *v1 = 1;
    *v2 = 2;
    *v3 = 3;

    assert(queue_dyarr_enqueue(q, v1) == true);
    assert(queue_dyarr_enqueue(q, v2) == true);
    assert(queue_dyarr_enqueue(q, v3) == true);
    assert(q->size == 3);
    assert(*(int *)q->data[0] == 3);
    assert(*(int *)q->data[1] == 2);
    assert(*(int *)q->data[2] == 1);
    printf("[OK] Enqueued 3 elements\n");

    int *peek = (int *)queue_dyarr_peak(q);
    assert(*peek == 1);
    printf("[OK] Peeked value is 1\n");

    assert(queue_dyarr_dequeue(q) == true);
    assert(q->size == 2);
    assert(*(int *)q->data[0] == 2);
    assert(*(int *)q->data[1] == 1);
    peek = (int *)queue_dyarr_peak(q);
    assert(*peek == 1);
    printf("[OK] Dequeued once, peek is still 1, size reduced by 1, first element changed\n");

    assert(queue_dyarr_dequeue(q) == true);
    assert(q->size == 1);
    assert(*(int *)q->data[0] == 1);
    peek = (int *)queue_dyarr_peak(q);
    assert(*peek == 1);
    printf("[OK] Dequeued again, peek is still 1, size reduced by 1, first element changed\n");

    assert(queue_dyarr_dequeue(q) == true);
    assert(q->size == 0);
    assert(queue_dyarr_peak(q) == NULL);
    printf("[OK] Dequeued last element, queue is now empty\n");

    queue_dyarr_destroy(q);
    printf("[OK] Queue destroyed\n");
}

int main()
{
    assert_queue_dyarr();

    return EXIT_SUCCESS;
}
