#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct llist_node_s
{
    void *data;
    struct llist_node_s *next;
} llist_node_s;

typedef struct
{
    llist_node_s *head;
    llist_node_s *tail;
    unsigned int total;
} llist_s;

llist_node_s *llist_create_node(void *data);

void llist_destroy_node(llist_node_s *node);

llist_s *llist_create();

void llist_destroy(llist_s *ll);

bool llist_append(llist_s *ll, llist_node_s *node);

bool llist_prepend(llist_s *ll, llist_node_s *node);

bool llist_insert_before_at(llist_s *ll, llist_node_s *node, size_t pos);

bool llist_delete_at(llist_s *ll, size_t pos);

llist_node_s *llist_get_node_at(llist_s *ll, size_t pos);

#endif
