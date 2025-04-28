#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef struct node_s
{
    void *data;
    struct node_s *next;
} node_s;

typedef struct
{
    node_s *head;
    node_s *tail;
    unsigned int total;
} linked_list_s;

linked_list_s *linked_list_create();

void linked_list_destroy(linked_list_s *ll);

bool linked_list_append(linked_list_s *ll, node_s *node);

bool linked_list_prepend(linked_list_s *ll, node_s *node);

#endif
