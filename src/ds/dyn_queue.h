#ifndef QUEUE_H
#define QUEUE_H

#include "dynamic_array.h"

typedef dyn_arr_s dyn_queue_s;

dyn_queue_s *dyn_queue_create();

bool dyn_queue_enqueue(dyn_queue_s *q, void *value);

bool dyn_queue_dequeue(dyn_queue_s *q);

void *dyn_queue_peak(dyn_queue_s *q);

void dyn_queue_destroy(dyn_queue_s *q);

#endif
