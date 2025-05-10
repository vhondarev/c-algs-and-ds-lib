#ifndef QUEUE_DLLIST_H
#define QUEUE_DLLIST_H

#include "linked_list_double.h"

typedef dllist_s queue_dllist_s;

typedef dllist_node_s queue_dllist_node_s;

queue_dllist_node_s *queue_dllist_create_node(void *data);

void queue_dllist_destroy_node(queue_dllist_node_s *node);

queue_dllist_s *queue_dllist_create();

void queue_dllist_destroy(queue_dllist_s *queue);

bool queue_dllist_enqueue(queue_dllist_s *queue, dllist_node_s *node);

bool queue_dllist_dequeue(queue_dllist_s *queue);

queue_dllist_node_s *queue_dllist_peek(queue_dllist_s *queue);

#endif
