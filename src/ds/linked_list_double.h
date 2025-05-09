#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct dl_list_node_s
{
    void *data;
    struct dl_list_node_s *prev;
    struct dl_list_node_s *next;
} dl_list_node_s;

typedef struct
{
    dl_list_node_s *head;
    dl_list_node_s *tail;
    unsigned int total;
} dl_list_s;

dl_list_node_s *dl_list_create_node(void *data);

void dl_list_destroy_node(dl_list_node_s *node);

dl_list_s *dl_list_create();

void dl_list_destroy(dl_list_s *dll);

int dl_list_append(dl_list_s *dll, dl_list_node_s *node);

int dl_list_prepend(dl_list_s *dll, dl_list_node_s *node);

bool dl_list_insert_before_at(dl_list_s *dll, dl_list_node_s *node, size_t pos);

dl_list_node_s *dl_list_get_node_at(dl_list_s *dll, size_t pos);

dl_list_node_s *dl_list_get_node(dl_list_s *dll, dl_list_node_s *node);

bool dl_list_delete_at(dl_list_s *dll, size_t pos);

bool dl_list_delete_node(dl_list_s *dll, dl_list_node_s *node);

bool dl_list_node_in(dl_list_s *dll, dl_list_node_s *node);

#endif
