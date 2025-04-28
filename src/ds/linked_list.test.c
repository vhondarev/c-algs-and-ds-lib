#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

node_s *create_node(void *data)
{
    node_s *node = malloc(sizeof(node_s));
    assert(node != NULL);
    node->data = data;
    node->next = NULL;
    return node;
}

void assert_linked_list_create_empty()
{
    linked_list_s *ll = linked_list_create();
    assert(ll != NULL);
    assert(ll->head == NULL);
    assert(ll->tail == NULL);
    assert(ll->total == 0);
    linked_list_destroy(ll);
    printf("[OK] - Created empty linked list\n");
}

void assert_linked_list_append()
{
    linked_list_s *ll = linked_list_create();
    int *data1 = malloc(sizeof(int));
    int *data2 = malloc(sizeof(int));
    *data1 = 10;
    *data2 = 10;
    node_s *node1 = create_node(data1);
    node_s *node2 = create_node(data2);

    assert(linked_list_append(ll, NULL) == false);
    assert(ll->head == NULL);
    assert(ll->tail == NULL);
    assert(ll->total == 0);
    printf("[OK] - Appending NULL node returns false\n");

    assert(linked_list_append(NULL, node1) == false);
    printf("[OK] - Appending to NULL list returns false\n");

    assert(linked_list_append(ll, node1) == true);
    assert(ll->head == node1);
    assert(ll->tail == node1);
    assert(ll->total == 1);
    printf("[OK] - Appended first node to empty list\n");

    assert(linked_list_append(ll, node2) == true);
    assert(ll->head == node1);
    assert(ll->tail == node2);
    assert(node1->next == node2);
    assert(ll->total == 2);
    printf("[OK] - Appended second node to list\n");

    linked_list_destroy(ll);
}

void assert_linked_list_prepend()
{
    linked_list_s *ll = linked_list_create();
    int *data1 = malloc(sizeof(int));
    int *data2 = malloc(sizeof(int));
    *data1 = 10;
    *data2 = 10;
    node_s *node1 = create_node(data1);
    node_s *node2 = create_node(data2);

    assert(linked_list_prepend(ll, NULL) == false);
    assert(ll->head == NULL);
    assert(ll->tail == NULL);
    assert(ll->total == 0);
    printf("[OK] - Prepending NULL node returns false\n");

    assert(linked_list_prepend(ll, node1) == true);
    assert(ll->head == node1);
    assert(ll->tail == node1);
    assert(ll->total == 1);
    printf("[OK] - Prepended first node to empty list\n");

    assert(linked_list_prepend(ll, node2) == true);
    assert(ll->head == node2);
    assert(ll->tail == node1);
    assert(node2->next == node1);
    assert(ll->total == 2);
    printf("[OK] - Prepended node to non-empty list\n");

    linked_list_destroy(ll);
}

void assert_linked_list_destroy_empty()
{
    linked_list_s *ll = linked_list_create();
    linked_list_destroy(ll);
    printf("[OK] - Destroyed empty linked list\n");
}

void assert_linked_list_destroy_single_node()
{
    linked_list_s *ll = linked_list_create();
    int *data = malloc(sizeof(int));
    *data = 10;

    node_s *node = create_node(data);
    linked_list_append(ll, node);
    linked_list_destroy(ll);
    printf("[OK] - Destroyed linked list with one node\n");

    linked_list_destroy(NULL);
    printf("[OK] - Destroying NULL linked list handled gracefully\n");
}
int main()
{
    assert_linked_list_create_empty();
    assert_linked_list_append();
    assert_linked_list_prepend();
    assert_linked_list_destroy_empty();
    assert_linked_list_destroy_single_node();

    return EXIT_SUCCESS;
}
