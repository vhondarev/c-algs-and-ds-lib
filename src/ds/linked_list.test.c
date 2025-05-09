#include <assert.h>
#include <stdio.h>

#include "linked_list.h"

void assert_create_node()
{
    int *value = malloc(sizeof(int));
    *value = 123;

    l_list_node_s *node = l_list_create_node(value);
    assert(node != NULL);
    assert(node->data == value);
    assert(node->next == NULL);
    printf("[OK] - Ll created node with valid data\n");

    free(value);
    free(node);

    l_list_node_s *nul_list_data_node = l_list_create_node(NULL);
    assert(nul_list_data_node != NULL);
    assert(nul_list_data_node->data == NULL);
    assert(nul_list_data_node->next == NULL);
    printf("[OK] - Ll created node with NULL data\n");

    free(nul_list_data_node);
}

void assert_destroy_node()
{
    l_list_destroy_node(NULL);
    printf("[OK] - Ll destroying NULL node\n");

    int *data = malloc(sizeof(int));
    *data = 42;
    l_list_node_s *node_with_data = malloc(sizeof(l_list_node_s));
    node_with_data->data = data;
    node_with_data->next = NULL;

    l_list_destroy_node(node_with_data);
    printf("[OK] - Ll destroyed node with non-NULL data\n");

    l_list_node_s *node_without_data = malloc(sizeof(l_list_node_s));
    node_without_data->data = NULL;
    node_without_data->next = NULL;

    l_list_destroy_node(node_without_data);
    printf("[OK] - Ll destroyed node with NULL data\n");
}

void assert_l_list_create()
{
    l_list_s *ll = l_list_create();
    assert(ll != NULL);
    assert(ll->head == NULL);
    assert(ll->tail == NULL);
    assert(ll->total == 0);
    l_list_destroy(ll);
    printf("[OK] - Ll created empty linked list\n");
}

void assert_l_list_destroy()
{
    l_list_s *ll = l_list_create();
    int *data = malloc(sizeof(int));
    *data = 10;

    l_list_node_s *node = l_list_create_node(data);
    l_list_append(ll, node);
    l_list_destroy(ll);
    printf("[OK] - Ll destroyed with one node\n");

    l_list_destroy(NULL);
    printf("[OK] - Ll destroying NULL\n");
}

void assert_l_list_append()
{
    l_list_s *ll = l_list_create();
    int *data1 = malloc(sizeof(int));
    int *data2 = malloc(sizeof(int));
    *data1 = 10;
    *data2 = 10;
    l_list_node_s *node1 = l_list_create_node(data1);
    l_list_node_s *node2 = l_list_create_node(data2);

    assert(l_list_append(ll, NULL) == false);
    assert(ll->head == NULL);
    assert(ll->tail == NULL);
    assert(ll->total == 0);
    printf("[OK] - Ll appending NULL node\n");

    assert(l_list_append(NULL, node1) == false);
    printf("[OK] - Ll appending to NULL \n");

    assert(l_list_append(ll, node1) == true);
    assert(ll->head == node1);
    assert(ll->tail == node1);
    assert(ll->total == 1);
    printf("[OK] - Ll appended first node to empty list\n");

    assert(l_list_append(ll, node2) == true);
    assert(ll->head == node1);
    assert(ll->tail == node2);
    assert(node1->next == node2);
    assert(ll->total == 2);
    printf("[OK] - Ll appended second node to list\n");

    l_list_destroy(ll);
}

void assert_l_list_prepend()
{
    l_list_s *ll = l_list_create();
    int *data1 = malloc(sizeof(int));
    int *data2 = malloc(sizeof(int));
    *data1 = 10;
    *data2 = 10;
    l_list_node_s *node1 = l_list_create_node(data1);
    l_list_node_s *node2 = l_list_create_node(data2);

    assert(l_list_prepend(ll, NULL) == false);
    assert(ll->head == NULL);
    assert(ll->tail == NULL);
    assert(ll->total == 0);
    printf("[OK] - Ll prepending NULL\n");

    assert(l_list_prepend(ll, node1) == true);
    assert(ll->head == node1);
    assert(ll->tail == node1);
    assert(ll->total == 1);
    printf("[OK] - Ll prepended first node to empty list\n");

    assert(l_list_prepend(ll, node2) == true);
    assert(ll->head == node2);
    assert(ll->tail == node1);
    assert(node2->next == node1);
    assert(ll->total == 2);
    printf("[OK] - Ll prepended node to non-empty list\n");

    l_list_destroy(ll);
}

void assert_l_list_insert()
{
    l_list_s *ll = l_list_create();
    int *d1 = malloc(sizeof(int));
    int *d2 = malloc(sizeof(int));
    int *d3 = malloc(sizeof(int));
    int *dmid = malloc(sizeof(int));
    *d1 = 1;
    *d2 = 2;
    *d3 = 3;
    *dmid = 99;

    l_list_node_s *n1 = l_list_create_node(d1);
    l_list_node_s *n2 = l_list_create_node(d2);
    l_list_node_s *n3 = l_list_create_node(d3);
    l_list_node_s *nmid = l_list_create_node(dmid);

    assert(l_list_insert_before_at(NULL, n1, 0) == false);
    assert(l_list_insert_before_at(ll, NULL, 0) == false);
    assert(l_list_insert_before_at(ll, n1, -1) == false);
    assert(l_list_insert_before_at(ll, n1, 1) == false);
    printf("[OK] - Ll invalid insertions handled correctly\n");

    assert(l_list_insert_before_at(ll, n1, 0) == true);
    assert(ll->head == n1);
    assert(ll->tail == n1);
    assert(ll->total == 1);
    printf("[OK] - Ll insert at position 0 (prepend)\n");

    assert(l_list_insert_before_at(ll, n2, 0) == true);
    assert(ll->head == n2);
    assert(ll->tail == n1);
    assert(ll->total == 2);
    printf("[OK] - Ll insert at position total (append)\n");

    assert(l_list_insert_before_at(ll, nmid, 1) == true);
    assert(ll->head == n2);
    assert(n2->next == nmid);
    assert(nmid->next == n1);
    assert(ll->total == 3);
    printf("[OK] - Ll insert in the middle of list\n");

    assert(l_list_insert_before_at(ll, n3, 2) == true);
    assert(ll->head == n2);
    assert(n3->next == n1);
    assert(ll->tail == n1);
    assert(ll->total == 4);
    printf("[OK] - Ll insert before a new tail\n");

    l_list_destroy(ll);
}

void assert_l_list_delete_at()
{
    assert(l_list_delete_at(NULL, 0) == false);
    printf("[OK] - Ll delete NULL node\n");

    l_list_s *ll = l_list_create();

    assert(l_list_delete_at(ll, 0) == false);
    printf("[OK] - Ll delete node from empty list\n");

    int *d1 = malloc(sizeof(int));
    int *d2 = malloc(sizeof(int));
    int *d3 = malloc(sizeof(int));
    int *d4 = malloc(sizeof(int));
    *d1 = 10;
    *d2 = 20;
    *d3 = 30;
    *d4 = 40;
    l_list_node_s *n1 = l_list_create_node(d1);
    l_list_node_s *n2 = l_list_create_node(d2);
    l_list_node_s *n3 = l_list_create_node(d3);
    l_list_node_s *n4 = l_list_create_node(d4);

    assert(l_list_append(ll, n1) == true);
    assert(l_list_append(ll, n2) == true);
    assert(l_list_append(ll, n3) == true);
    assert(l_list_append(ll, n4) == true);

    assert(l_list_delete_at(ll, 10) == false);
    printf("[OK] - Ll delete node with a wrong index\n");

    assert(l_list_delete_at(ll, 0) == true);
    assert(l_list_get_node_at(ll, ll->total - 1) == n2);
    printf("[OK] - Ll delete first node\n");

    assert(l_list_delete_at(ll, ll->total / 2) == true);
    assert(l_list_get_node_at(ll, ll->total - 1) == n4);
    printf("[OK] - Ll delete middle node\n");

    assert(l_list_delete_at(ll, ll->total - 1) == true);
    assert(l_list_get_node_at(ll, ll->total - 1) == n2);
    printf("[OK] - Ll delete end node\n");

    assert(l_list_delete_at(ll, ll->total - 1) == true);
    assert(ll->head == NULL);
    assert(ll->tail == NULL);
    assert(ll->total == 0);
    printf("[OK] - Delete last node\n");

    l_list_destroy(ll);
}

void assert_l_list_get_node()
{
    assert(l_list_get_node_at(NULL, 0) == NULL);
    printf("[OK] - Ll get node from NULL list\n");

    l_list_s *l_list_empty = l_list_create();
    assert(l_list_get_node_at(l_list_empty, 0) == NULL);
    printf("[OK] - Ll get node from empty list\n");

    l_list_destroy(l_list_empty);

    l_list_s *ll = l_list_create();

    int *v1 = malloc(sizeof(int));
    int *v2 = malloc(sizeof(int));
    int *v3 = malloc(sizeof(int));
    *v1 = 10;
    *v2 = 20;
    *v3 = 30;

    l_list_node_s *n1 = l_list_create_node(v1);
    l_list_node_s *n2 = l_list_create_node(v2);
    l_list_node_s *n3 = l_list_create_node(v3);

    l_list_append(ll, n1);
    l_list_append(ll, n2);
    l_list_append(ll, n3);

    l_list_node_s *got = l_list_get_node_at(ll, 0);
    assert(got == n1);
    assert(*(int *)got->data == 10);
    printf("[OK] - Ll get node at position 0\n");

    got = l_list_get_node_at(ll, 1);
    assert(got == n2);
    assert(*(int *)got->data == 20);
    printf("[OK] - Ll get node at position 1\n");

    got = l_list_get_node_at(ll, 2);
    assert(got == n3);
    assert(*(int *)got->data == 30);
    printf("[OK] - Ll get node at position 2\n");

    assert(l_list_get_node_at(ll, 3) == NULL);
    printf("[OK] - Ll get node at out-of-bounds index\n");

    assert(l_list_get_node_at(ll, -1) == NULL);
    printf("[OK] - Ll get node at negative index\n");

    l_list_destroy(ll);
}

int main()
{
    assert_create_node();
    assert_destroy_node();
    assert_l_list_create();
    assert_l_list_destroy();
    assert_l_list_append();
    assert_l_list_prepend();
    assert_l_list_insert();
    assert_l_list_get_node();

    return EXIT_SUCCESS;
}
