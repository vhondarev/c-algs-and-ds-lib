#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

void assert_create_node()
{
    int *value = malloc(sizeof(int));
    *value = 123;

    node_s *node = create_node(value);
    assert(node != NULL);
    assert(node->data == value);
    assert(node->next == NULL);
    printf("[OK] - Created node with valid data\n");

    free(value);
    free(node);

    node_s *null_data_node = create_node(NULL);
    assert(null_data_node != NULL);
    assert(null_data_node->data == NULL);
    assert(null_data_node->next == NULL);
    printf("[OK] - Created node with NULL data\n");

    free(null_data_node);
}

void assert_destroy_node()
{
    destroy_node(NULL);
    printf("[OK] - Destroying NULL node handled gracefully\n");

    int *data = malloc(sizeof(int));
    *data = 42;
    node_s *node_with_data = malloc(sizeof(node_s));
    node_with_data->data = data;
    node_with_data->next = NULL;

    destroy_node(node_with_data);
    printf("[OK] - Destroyed node with non-NULL data\n");

    node_s *node_without_data = malloc(sizeof(node_s));
    node_without_data->data = NULL;
    node_without_data->next = NULL;

    destroy_node(node_without_data);
    printf("[OK] - Destroyed node with NULL data\n");
}

void assert_linked_list_create()
{
    linked_list_s *ll = linked_list_create();
    assert(ll != NULL);
    assert(ll->head == NULL);
    assert(ll->tail == NULL);
    assert(ll->total == 0);
    linked_list_destroy(ll);
    printf("[OK] - Created empty linked list\n");
}

void assert_linked_list_destroy()
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

void assert_linked_list_insert()
{
    linked_list_s *ll = linked_list_create();
    int *d1 = malloc(sizeof(int));
    int *d2 = malloc(sizeof(int));
    int *d3 = malloc(sizeof(int));
    int *dmid = malloc(sizeof(int));
    *d1 = 1;
    *d2 = 2;
    *d3 = 3;
    *dmid = 99;

    node_s *n1 = create_node(d1);
    node_s *n2 = create_node(d2);
    node_s *n3 = create_node(d3);
    node_s *nmid = create_node(dmid);

    assert(linked_list_insert(NULL, n1, 0) == false);
    assert(linked_list_insert(ll, NULL, 0) == false);
    assert(linked_list_insert(ll, n1, -1) == false);
    assert(linked_list_insert(ll, n1, 1) == false); // total is 0
    printf("[OK] - Invalid insertions handled correctly\n");

    assert(linked_list_insert(ll, n1, 0) == true);
    assert(ll->head == n1);
    assert(ll->tail == n1);
    assert(ll->total == 1);
    printf("[OK] - Insert at position 0 (prepend) succeeded\n");

    assert(linked_list_insert(ll, n3, 1) == true);
    assert(ll->head == n1);
    assert(ll->tail == n3);
    assert(ll->total == 2);
    printf("[OK] - Insert at position total (append) succeeded\n");

    assert(linked_list_insert(ll, nmid, 1) == true);
    assert(ll->total == 3);
    assert(ll->head == n1);
    assert(n1->next == nmid);
    assert(nmid->next == n3);
    printf("[OK] - Insert in the middle of list succeeded\n");

    assert(linked_list_insert(ll, n2, 3) == true); // position after n3
    assert(ll->tail == n2);
    assert(ll->total == 4);
    assert(n3->next == n2);
    printf("[OK] - Insert at new tail succeeded\n");

    linked_list_destroy(ll);
}

void assert_linked_list_get_node()
{
    assert(linked_list_get_node(NULL, 0) == NULL);
    printf("[OK] - Get node from NULL list returns NULL\n");

    linked_list_s *ll_empty = linked_list_create();
    assert(linked_list_get_node(ll_empty, 0) == NULL);
    printf("[OK] - Get node from empty list returns NULL\n");

    linked_list_destroy(ll_empty);

    linked_list_s *ll = linked_list_create();

    int *v1 = malloc(sizeof(int));
    int *v2 = malloc(sizeof(int));
    int *v3 = malloc(sizeof(int));
    *v1 = 10;
    *v2 = 20;
    *v3 = 30;

    node_s *n1 = create_node(v1);
    node_s *n2 = create_node(v2);
    node_s *n3 = create_node(v3);

    linked_list_append(ll, n1);
    linked_list_append(ll, n2);
    linked_list_append(ll, n3);

    node_s *got = linked_list_get_node(ll, 0);
    assert(got == n1);
    assert(*(int *)got->data == 10);
    printf("[OK] - Get node at position 0\n");

    got = linked_list_get_node(ll, 1);
    assert(got == n2);
    assert(*(int *)got->data == 20);
    printf("[OK] - Get node at position 1\n");

    got = linked_list_get_node(ll, 2);
    assert(got == n3);
    assert(*(int *)got->data == 30);
    printf("[OK] - Get node at position 2\n");

    assert(linked_list_get_node(ll, 3) == NULL);
    printf("[OK] - Get node at out-of-bounds index returns NULL\n");

    assert(linked_list_get_node(ll, -1) == NULL);
    printf("[OK] - Get node at negative index returns NULL\n");

    linked_list_destroy(ll);
}

int main()
{
    assert_create_node();
    assert_destroy_node();
    assert_linked_list_create();
    assert_linked_list_destroy();
    assert_linked_list_append();
    assert_linked_list_prepend();
    assert_linked_list_insert();
    assert_linked_list_get_node();

    return EXIT_SUCCESS;
}
