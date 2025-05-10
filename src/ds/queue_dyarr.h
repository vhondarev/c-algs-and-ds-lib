#ifndef QUEUE_DYARR_H
#define QUEUE_DYARR_H

#include "dynamic_array.h"

typedef darr_s queue_dyarr_s;

queue_dyarr_s *queue_dyarr_create();

void queue_dyarr_destroy(queue_dyarr_s *q);

bool queue_dyarr_enqueue(queue_dyarr_s *q, void *data);

bool queue_dyarr_dequeue(queue_dyarr_s *q);

void *queue_dyarr_peak(queue_dyarr_s *q);

#endif
