#include <assert.h>
#include <stdio.h>

#include "linked_list.h"

void assert_create_node()
{
    int *value = malloc(sizeof(int));
    *value = 123;

    ll_node_s *node = ll_create_node(value);
    assert(node != NULL);
    assert(node->data == value);
    assert(node->next == NULL);
    printf("[OK] - Created node with valid data\n");

    free(value);
    free(node);

    ll_node_s *null_data_node = ll_create_node(NULL);
    assert(null_data_node != NULL);
    assert(null_data_node->data == NULL);
    assert(null_data_node->next == NULL);
    printf("[OK] - Created node with NULL data\n");

    free(null_data_node);
}

void assert_destroy_node()
{
    ll_destroy_node(NULL);
    printf("[OK] - Destroying NULL node handled gracefully\n");

    int *data = malloc(sizeof(int));
    *data = 42;
    ll_node_s *node_with_data = malloc(sizeof(ll_node_s));
    node_with_data->data = data;
    node_with_data->next = NULL;

    ll_destroy_node(node_with_data);
    printf("[OK] - Destroyed node with non-NULL data\n");

    ll_node_s *node_without_data = malloc(sizeof(ll_node_s));
    node_without_data->data = NULL;
    node_without_data->next = NULL;

    ll_destroy_node(node_without_data);
    printf("[OK] - Destroyed node with NULL data\n");
}

void assert_ll_create()
{
    ll_s *ll = ll_create();
    assert(ll != NULL);
    assert(ll->head == NULL);
    assert(ll->tail == NULL);
    assert(ll->total == 0);
    ll_destroy(ll);
    printf("[OK] - Created empty linked list\n");
}

void assert_ll_destroy()
{
    ll_s *ll = ll_create();
    int *data = malloc(sizeof(int));
    *data = 10;

    ll_node_s *node = ll_create_node(data);
    ll_append(ll, node);
    ll_destroy(ll);
    printf("[OK] - Destroyed linked list with one node\n");

    ll_destroy(NULL);
    printf("[OK] - Destroying NULL linked list handled gracefully\n");
}

void assert_ll_append()
{
    ll_s *ll = ll_create();
    int *data1 = malloc(sizeof(int));
    int *data2 = malloc(sizeof(int));
    *data1 = 10;
    *data2 = 10;
    ll_node_s *node1 = ll_create_node(data1);
    ll_node_s *node2 = ll_create_node(data2);

    assert(ll_append(ll, NULL) == false);
    assert(ll->head == NULL);
    assert(ll->tail == NULL);
    assert(ll->total == 0);
    printf("[OK] - Appending NULL node returns false\n");

    assert(ll_append(NULL, node1) == false);
    printf("[OK] - Appending to NULL list returns false\n");

    assert(ll_append(ll, node1) == true);
    assert(ll->head == node1);
    assert(ll->tail == node1);
    assert(ll->total == 1);
    printf("[OK] - Appended first node to empty list\n");

    assert(ll_append(ll, node2) == true);
    assert(ll->head == node1);
    assert(ll->tail == node2);
    assert(node1->next == node2);
    assert(ll->total == 2);
    printf("[OK] - Appended second node to list\n");

    ll_destroy(ll);
}

void assert_ll_prepend()
{
    ll_s *ll = ll_create();
    int *data1 = malloc(sizeof(int));
    int *data2 = malloc(sizeof(int));
    *data1 = 10;
    *data2 = 10;
    ll_node_s *node1 = ll_create_node(data1);
    ll_node_s *node2 = ll_create_node(data2);

    assert(ll_prepend(ll, NULL) == false);
    assert(ll->head == NULL);
    assert(ll->tail == NULL);
    assert(ll->total == 0);
    printf("[OK] - Prepending NULL node returns false\n");

    assert(ll_prepend(ll, node1) == true);
    assert(ll->head == node1);
    assert(ll->tail == node1);
    assert(ll->total == 1);
    printf("[OK] - Prepended first node to empty list\n");

    assert(ll_prepend(ll, node2) == true);
    assert(ll->head == node2);
    assert(ll->tail == node1);
    assert(node2->next == node1);
    assert(ll->total == 2);
    printf("[OK] - Prepended node to non-empty list\n");

    ll_destroy(ll);
}

void assert_ll_insert()
{
    ll_s *ll = ll_create();
    int *d1 = malloc(sizeof(int));
    int *d2 = malloc(sizeof(int));
    int *d3 = malloc(sizeof(int));
    int *dmid = malloc(sizeof(int));
    *d1 = 1;
    *d2 = 2;
    *d3 = 3;
    *dmid = 99;

    ll_node_s *n1 = ll_create_node(d1);
    ll_node_s *n2 = ll_create_node(d2);
    ll_node_s *n3 = ll_create_node(d3);
    ll_node_s *nmid = ll_create_node(dmid);

    assert(ll_insert(NULL, n1, 0) == false);
    assert(ll_insert(ll, NULL, 0) == false);
    assert(ll_insert(ll, n1, -1) == false);
    assert(ll_insert(ll, n1, 1) == false); // total is 0
    printf("[OK] - Invalid insertions handled correctly\n");

    assert(ll_insert(ll, n1, 0) == true);
    assert(ll->head == n1);
    assert(ll->tail == n1);
    assert(ll->total == 1);
    printf("[OK] - Insert at position 0 (prepend) succeeded\n");

    assert(ll_insert(ll, n3, 1) == true);
    assert(ll->head == n1);
    assert(ll->tail == n3);
    assert(ll->total == 2);
    printf("[OK] - Insert at position total (append) succeeded\n");

    assert(ll_insert(ll, nmid, 1) == true);
    assert(ll->total == 3);
    assert(ll->head == n1);
    assert(n1->next == nmid);
    assert(nmid->next == n3);
    printf("[OK] - Insert in the middle of list succeeded\n");

    assert(ll_insert(ll, n2, 3) == true); // position after n3
    assert(ll->tail == n2);
    assert(ll->total == 4);
    assert(n3->next == n2);
    printf("[OK] - Insert at new tail succeeded\n");

    ll_destroy(ll);
}

void assert_ll_get_node()
{
    assert(ll_get_node_at(NULL, 0) == NULL);
    printf("[OK] - Get node from NULL list returns NULL\n");

    ll_s *ll_empty = ll_create();
    assert(ll_get_node_at(ll_empty, 0) == NULL);
    printf("[OK] - Get node from empty list returns NULL\n");

    ll_destroy(ll_empty);

    ll_s *ll = ll_create();

    int *v1 = malloc(sizeof(int));
    int *v2 = malloc(sizeof(int));
    int *v3 = malloc(sizeof(int));
    *v1 = 10;
    *v2 = 20;
    *v3 = 30;

    ll_node_s *n1 = ll_create_node(v1);
    ll_node_s *n2 = ll_create_node(v2);
    ll_node_s *n3 = ll_create_node(v3);

    ll_append(ll, n1);
    ll_append(ll, n2);
    ll_append(ll, n3);

    ll_node_s *got = ll_get_node_at(ll, 0);
    assert(got == n1);
    assert(*(int *)got->data == 10);
    printf("[OK] - Get node at position 0\n");

    got = ll_get_node_at(ll, 1);
    assert(got == n2);
    assert(*(int *)got->data == 20);
    printf("[OK] - Get node at position 1\n");

    got = ll_get_node_at(ll, 2);
    assert(got == n3);
    assert(*(int *)got->data == 30);
    printf("[OK] - Get node at position 2\n");

    assert(ll_get_node_at(ll, 3) == NULL);
    printf("[OK] - Get node at out-of-bounds index returns NULL\n");

    assert(ll_get_node_at(ll, -1) == NULL);
    printf("[OK] - Get node at negative index returns NULL\n");

    ll_destroy(ll);
}

int main()
{
    assert_create_node();
    assert_destroy_node();
    assert_ll_create();
    assert_ll_destroy();
    assert_ll_append();
    assert_ll_prepend();
    assert_ll_insert();
    assert_ll_get_node();

    return EXIT_SUCCESS;
}
