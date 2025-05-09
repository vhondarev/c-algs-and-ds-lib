#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct l_list_node_s
{
    void *data;
    struct l_list_node_s *next;
} l_list_node_s;

typedef struct
{
    l_list_node_s *head;
    l_list_node_s *tail;
    unsigned int total;
} l_list_s;

l_list_node_s *l_list_create_node(void *data);

void l_list_destroy_node(l_list_node_s *node);

l_list_s *l_list_create();

void l_list_destroy(l_list_s *ll);

bool l_list_append(l_list_s *ll, l_list_node_s *node);

bool l_list_prepend(l_list_s *ll, l_list_node_s *node);

bool l_list_insert_before_at(l_list_s *ll, l_list_node_s *node, size_t pos);

bool l_list_delete_at(l_list_s *ll, size_t pos);

l_list_node_s *l_list_get_node_at(l_list_s *ll, size_t pos);

#endif
