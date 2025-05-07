#ifndef QUEUE_CIRC_H
#define QUEUE_CIRC_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    int front, back;
    size_t length;
    void **data;
} queue_circ_s;

queue_circ_s *queue_circ_init(size_t lenght);

void queue_circ_destroy(queue_circ_s *q);

bool queue_circ_empty(queue_circ_s *q);

bool queue_circ_full(queue_circ_s *q);

bool queue_circ_enqueue(queue_circ_s *q, void *data);

bool queue_circ_dequeue(queue_circ_s *q);

#endif
