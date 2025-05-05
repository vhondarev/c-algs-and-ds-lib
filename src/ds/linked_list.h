#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>

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
} ll_s;

node_s *create_node(void *data);

void destroy_node(node_s *node);

ll_s *ll_create();

void ll_destroy(ll_s *ll);

bool ll_append(ll_s *ll, node_s *node);

bool ll_prepend(ll_s *ll, node_s *node);

bool ll_insert(ll_s *ll, node_s *node, size_t pos);

bool ll_delete(ll_s *ll, size_t pos);

node_s *ll_get_node_at(ll_s *ll, size_t pos);

#endif
