#include <assert.h>
#include <stdio.h>

#include "linked_list.h"

void assert_create_node()
{
    int *value = malloc(sizeof(int));
    *value = 123;

    llist_node_s *node = llist_create_node(value);
    assert(node != NULL);
    assert(node->data == value);
    assert(node->next == NULL);
    printf("[OK] - Ll created node with valid data\n");

    free(value);
    free(node);

    llist_node_s *nullist_data_node = llist_create_node(NULL);
    assert(nullist_data_node != NULL);
    assert(nullist_data_node->data == NULL);
    assert(nullist_data_node->next == NULL);
    printf("[OK] - Ll created node with NULL data\n");

    free(nullist_data_node);
}

void assert_destroy_node()
{
    llist_destroy_node(NULL);
    printf("[OK] - Ll destroying NULL node\n");

    int *data = malloc(sizeof(int));
    *data = 42;
    llist_node_s *node_with_data = malloc(sizeof(llist_node_s));
    node_with_data->data = data;
    node_with_data->next = NULL;

    llist_destroy_node(node_with_data);
    printf("[OK] - Ll destroyed node with non-NULL data\n");

    llist_node_s *node_without_data = malloc(sizeof(llist_node_s));
    node_without_data->data = NULL;
    node_without_data->next = NULL;

    llist_destroy_node(node_without_data);
    printf("[OK] - Ll destroyed node with NULL data\n");
}

void assert_llist_create()
{
    llist_s *ll = llist_create();
    assert(ll != NULL);
    assert(ll->head == NULL);
    assert(ll->tail == NULL);
    assert(ll->total == 0);
    llist_destroy(ll);
    printf("[OK] - Ll created empty linked list\n");
}

void assert_llist_destroy()
{
    llist_s *ll = llist_create();
    int *data = malloc(sizeof(int));
    *data = 10;

    llist_node_s *node = llist_create_node(data);
    llist_append(ll, node);
    llist_destroy(ll);
    printf("[OK] - Ll destroyed with one node\n");

    llist_destroy(NULL);
    printf("[OK] - Ll destroying NULL\n");
}

void assert_llist_append()
{
    llist_s *ll = llist_create();
    int *data1 = malloc(sizeof(int));
    int *data2 = malloc(sizeof(int));
    *data1 = 10;
    *data2 = 10;
    llist_node_s *node1 = llist_create_node(data1);
    llist_node_s *node2 = llist_create_node(data2);

    assert(llist_append(ll, NULL) == false);
    assert(ll->head == NULL);
    assert(ll->tail == NULL);
    assert(ll->total == 0);
    printf("[OK] - Ll appending NULL node\n");

    assert(llist_append(NULL, node1) == false);
    printf("[OK] - Ll appending to NULL \n");

    assert(llist_append(ll, node1) == true);
    assert(ll->head == node1);
    assert(ll->tail == node1);
    assert(ll->total == 1);
    printf("[OK] - Ll appended first node to empty list\n");

    assert(llist_append(ll, node2) == true);
    assert(ll->head == node1);
    assert(ll->tail == node2);
    assert(node1->next == node2);
    assert(ll->total == 2);
    printf("[OK] - Ll appended second node to list\n");

    llist_destroy(ll);
}

void assert_llist_prepend()
{
    llist_s *ll = llist_create();
    int *data1 = malloc(sizeof(int));
    int *data2 = malloc(sizeof(int));
    *data1 = 10;
    *data2 = 10;
    llist_node_s *node1 = llist_create_node(data1);
    llist_node_s *node2 = llist_create_node(data2);

    assert(llist_prepend(ll, NULL) == false);
    assert(ll->head == NULL);
    assert(ll->tail == NULL);
    assert(ll->total == 0);
    printf("[OK] - Ll prepending NULL\n");

    assert(llist_prepend(ll, node1) == true);
    assert(ll->head == node1);
    assert(ll->tail == node1);
    assert(ll->total == 1);
    printf("[OK] - Ll prepended first node to empty list\n");

    assert(llist_prepend(ll, node2) == true);
    assert(ll->head == node2);
    assert(ll->tail == node1);
    assert(node2->next == node1);
    assert(ll->total == 2);
    printf("[OK] - Ll prepended node to non-empty list\n");

    llist_destroy(ll);
}

void assert_llist_insert()
{
    llist_s *ll = llist_create();
    int *d1 = malloc(sizeof(int));
    int *d2 = malloc(sizeof(int));
    int *d3 = malloc(sizeof(int));
    int *dmid = malloc(sizeof(int));
    *d1 = 1;
    *d2 = 2;
    *d3 = 3;
    *dmid = 99;

    llist_node_s *n1 = llist_create_node(d1);
    llist_node_s *n2 = llist_create_node(d2);
    llist_node_s *n3 = llist_create_node(d3);
    llist_node_s *nmid = llist_create_node(dmid);

    assert(llist_insert_before_at(NULL, n1, 0) == false);
    assert(llist_insert_before_at(ll, NULL, 0) == false);
    assert(llist_insert_before_at(ll, n1, -1) == false);
    assert(llist_insert_before_at(ll, n1, 1) == false);
    printf("[OK] - Invalid insertions handled correctly\n");

    assert(llist_insert_before_at(ll, n1, 0) == true);
    assert(ll->head == n1);
    assert(ll->tail == n1);
    assert(ll->total == 1);
    printf("[OK] - Insert at position 0 (prepend)\n");

    assert(llist_insert_before_at(ll, n2, 0) == true);
    assert(ll->head == n2);
    assert(ll->tail == n1);
    assert(ll->total == 2);
    printf("[OK] - Insert at position total (append)\n");

    assert(llist_insert_before_at(ll, nmid, 1) == true);
    assert(ll->head == n2);
    assert(n2->next == nmid);
    assert(nmid->next == n1);
    assert(ll->total == 3);
    printf("[OK] - Insert in the middle of list\n");

    assert(llist_insert_before_at(ll, n3, 2) == true);
    assert(ll->head == n2);
    assert(n3->next == n1);
    assert(ll->tail == n1);
    assert(ll->total == 4);
    printf("[OK] - Insert before a new tail\n");

    llist_destroy(ll);
}

void assert_llist_delete_at()
{
    assert(llist_delete_at(NULL, 0) == false);
    printf("[OK] - Delete NULL node\n");

    llist_s *ll = llist_create();

    assert(llist_delete_at(ll, 0) == false);
    printf("[OK] - Delete node from empty list\n");

    int *d1 = malloc(sizeof(int));
    int *d2 = malloc(sizeof(int));
    int *d3 = malloc(sizeof(int));
    int *d4 = malloc(sizeof(int));
    *d1 = 10;
    *d2 = 20;
    *d3 = 30;
    *d4 = 40;
    llist_node_s *n1 = llist_create_node(d1);
    llist_node_s *n2 = llist_create_node(d2);
    llist_node_s *n3 = llist_create_node(d3);
    llist_node_s *n4 = llist_create_node(d4);

    assert(llist_append(ll, n1) == true);
    assert(llist_append(ll, n2) == true);
    assert(llist_append(ll, n3) == true);
    assert(llist_append(ll, n4) == true);

    assert(llist_delete_at(ll, 10) == false);
    printf("[OK] - Delete node with a wrong index\n");

    assert(llist_delete_at(ll, 0) == true);
    assert(llist_get_node_at(ll, ll->total - 1) == n2);
    printf("[OK] - Delete first node\n");

    assert(llist_delete_at(ll, ll->total / 2) == true);
    assert(llist_get_node_at(ll, ll->total - 1) == n4);
    printf("[OK] - Delete middle node\n");

    assert(llist_delete_at(ll, ll->total - 1) == true);
    assert(llist_get_node_at(ll, ll->total - 1) == n2);
    printf("[OK] - Delete end node\n");

    assert(llist_delete_at(ll, ll->total - 1) == true);
    assert(ll->head == NULL);
    assert(ll->tail == NULL);
    assert(ll->total == 0);
    printf("[OK] - Delete last node\n");

    llist_destroy(ll);
}

void assert_llist_get_node()
{
    assert(llist_get_node_at(NULL, 0) == NULL);
    printf("[OK] - Get node from NULL list\n");

    llist_s *llist_empty = llist_create();
    assert(llist_get_node_at(llist_empty, 0) == NULL);
    printf("[OK] - Get node from empty list\n");

    llist_destroy(llist_empty);

    llist_s *ll = llist_create();

    int *v1 = malloc(sizeof(int));
    int *v2 = malloc(sizeof(int));
    int *v3 = malloc(sizeof(int));
    *v1 = 10;
    *v2 = 20;
    *v3 = 30;

    llist_node_s *n1 = llist_create_node(v1);
    llist_node_s *n2 = llist_create_node(v2);
    llist_node_s *n3 = llist_create_node(v3);

    llist_append(ll, n1);
    llist_append(ll, n2);
    llist_append(ll, n3);

    llist_node_s *got = llist_get_node_at(ll, 0);
    assert(got == n1);
    assert(*(int *)got->data == 10);
    printf("[OK] - Get node at position 0\n");

    got = llist_get_node_at(ll, 1);
    assert(got == n2);
    assert(*(int *)got->data == 20);
    printf("[OK] - Get node at position 1\n");

    got = llist_get_node_at(ll, 2);
    assert(got == n3);
    assert(*(int *)got->data == 30);
    printf("[OK] - Get node at position 2\n");

    assert(llist_get_node_at(ll, 3) == NULL);
    printf("[OK] - Get node at out-of-bounds index\n");

    assert(llist_get_node_at(ll, -1) == NULL);
    printf("[OK] - Get node at negative index\n");

    llist_destroy(ll);
}

int main()
{
    assert_create_node();
    assert_destroy_node();
    assert_llist_create();
    assert_llist_destroy();
    assert_llist_append();
    assert_llist_prepend();
    assert_llist_insert();
    assert_llist_get_node();

    return EXIT_SUCCESS;
}
