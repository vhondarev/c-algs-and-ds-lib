#include <assert.h>
#include <stdio.h>

#include "queue_dyarr.h"

void assert_queue_dyarr_create_destroy()
{
    queue_dyarr_s *q = queue_dyarr_create();
    assert(q != NULL);
    printf("[OK] - Queue created\n");

    queue_dyarr_destroy(q);
    printf("[OK] - Queue destroyed\n");
}

void assert_queue_dyarr()
{
    queue_dyarr_s *q = queue_dyarr_create();

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
    assert(*(int *)q->data[0] == 1);
    assert(*(int *)q->data[1] == 2);
    assert(*(int *)q->data[2] == 3);
    printf("[OK] - Enqueued 3 elements\n");

    assert(queue_dyarr_dequeue(q) == true);
    assert(q->size == 2);
    assert(*(int *)q->data[0] == 2);
    assert(*(int *)q->data[1] == 3);
    printf("[OK] - Dequeued first item\n");

    assert(queue_dyarr_dequeue(q) == true);
    assert(q->size == 1);
    assert(*(int *)q->data[0] == 3);
    printf("[OK] - Dequeued second item\n");

    assert(queue_dyarr_dequeue(q) == true);
    assert(q->size == 0);
    assert(queue_dyarr_peak(q) == NULL);
    printf("[OK] - Dequeued last element\n");

    queue_dyarr_destroy(q);
}

void assert_queue_dyarr_peak()
{
    queue_dyarr_s *q = queue_dyarr_create();

    int *v1 = malloc(sizeof(int));
    int *v2 = malloc(sizeof(int));
    int *v3 = malloc(sizeof(int));
    *v1 = 1;
    *v2 = 2;
    *v3 = 3;

    assert(queue_dyarr_enqueue(q, v1) == true);
    assert(*(int *)queue_dyarr_peak(q) == 1);
    printf("[OK] - Peeked first enqueued value\n");

    assert(queue_dyarr_enqueue(q, v2) == true);
    assert(*(int *)queue_dyarr_peak(q) == 1);
    printf("[OK] - Peeked second enqueued value\n");

    assert(queue_dyarr_enqueue(q, v3) == true);
    assert(*(int *)queue_dyarr_peak(q) == 1);
    printf("[OK] - Peeked third enqueued value\n");

    assert(queue_dyarr_dequeue(q) == true);
    assert(*(int *)queue_dyarr_peak(q) == 2);
    printf("[OK] - Peeked first dequeued value\n");

    assert(queue_dyarr_dequeue(q) == true);
    assert(*(int *)queue_dyarr_peak(q) == 3);
    printf("[OK] - Peeked second dequeued value\n");

    assert(queue_dyarr_dequeue(q) == true);
    assert(queue_dyarr_peak(q) == NULL);
    assert(q->size == 0);
    printf("[OK] - Peeked empty queue\n");

    queue_dyarr_destroy(q);
}

int main()
{
    assert_queue_dyarr_create_destroy();
    assert_queue_dyarr();
    assert_queue_dyarr_peak();

    return EXIT_SUCCESS;
}
