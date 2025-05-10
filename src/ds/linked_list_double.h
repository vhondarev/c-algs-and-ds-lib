#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct dllist_node_s
{
    void *data;
    struct dllist_node_s *prev;
    struct dllist_node_s *next;
} dllist_node_s;

typedef struct
{
    dllist_node_s *head;
    dllist_node_s *tail;
    unsigned int total;
} dllist_s;

dllist_node_s *dllist_create_node(void *data);

void dllist_destroy_node(dllist_node_s *node);

dllist_s *dllist_create();

void dllist_destroy(dllist_s *dll);

bool dllist_append(dllist_s *dll, dllist_node_s *node);

bool dllist_prepend(dllist_s *dll, dllist_node_s *node);

bool dllist_insert_before_at(dllist_s *dll, dllist_node_s *node, size_t pos);

dllist_node_s *dllist_get_node_at(dllist_s *dll, size_t pos);

dllist_node_s *dllist_get_node(dllist_s *dll, dllist_node_s *node);

bool dllist_delete_at(dllist_s *dll, size_t pos);

bool dllist_delete_node(dllist_s *dll, dllist_node_s *node);

bool dllist_node_in(dllist_s *dll, dllist_node_s *node);

#endif
