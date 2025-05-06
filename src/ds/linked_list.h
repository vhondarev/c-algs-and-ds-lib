#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct ll_node_s
{
    void *data;
    struct ll_node_s *next;
} ll_node_s;

typedef struct
{
    ll_node_s *head;
    ll_node_s *tail;
    unsigned int total;
} ll_s;

ll_node_s *ll_create_node(void *data);

void ll_destroy_node(ll_node_s *node);

ll_s *ll_create();

void ll_destroy(ll_s *ll);

bool ll_append(ll_s *ll, ll_node_s *node);

bool ll_prepend(ll_s *ll, ll_node_s *node);

bool ll_insert(ll_s *ll, ll_node_s *node, size_t pos);

bool ll_delete(ll_s *ll, size_t pos);

ll_node_s *ll_get_node_at(ll_s *ll, size_t pos);

#endif
