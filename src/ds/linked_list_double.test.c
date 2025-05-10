#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list_double.h"

void assert_dllist_create_and_destroy_node()
{
    int *value = malloc(sizeof(int));
    *value = 123;

    dllist_node_s *dllist_node = dllist_create_node(value);
    assert(dllist_node != NULL);
    assert(dllist_node->data == value);
    assert(dllist_node->next == NULL);
    assert(dllist_node->prev == NULL);
    dllist_destroy_node(dllist_node);
    printf("[OK] - Created and destroyed node with valid data\n");

    dllist_node_s *null_data_node = dllist_create_node(NULL);
    assert(null_data_node != NULL);
    assert(null_data_node->data == NULL);
    assert(null_data_node->next == NULL);
    dllist_destroy_node(null_data_node);
    printf("[OK] - Created and destroyed node with NULL data\n");

    dllist_destroy_node(NULL);
    printf("[OK] - Destroying NULL node\n");
}

void assert_dllist_create_and_destroy()
{
    dllist_s *dll = dllist_create();
    assert(dll->head == NULL);
    assert(dll->tail == NULL);
    assert(dll->total == 0);
    printf("[OK] - Created empty\n");

    dllist_destroy(dll);
    printf("[OK] - Destroyed empty\n");
}

void assert_dllist_append_and_prepend()
{
    dllist_s *dll = dllist_create();
    assert(dll != NULL);

    int *val1 = malloc(sizeof(int));
    int *val2 = malloc(sizeof(int));
    int *val3 = malloc(sizeof(int));
    int *val4 = malloc(sizeof(int));
    int *val5 = malloc(sizeof(int));
    *val1 = 10;
    *val2 = 20;
    *val3 = 30;
    *val4 = 40;
    *val5 = 50;

    dllist_node_s *node1 = dllist_create_node(val1);
    dllist_node_s *node2 = dllist_create_node(val2);
    dllist_node_s *node3 = dllist_create_node(val3);
    dllist_node_s *node4 = dllist_create_node(val4);
    dllist_node_s *node5 = dllist_create_node(val5);

    assert(dllist_append(dll, node1) == true);
    assert(dll->head == node1);
    assert(dll->tail == node1);
    assert(dll->total == 1);
    assert(dll->head->next == NULL);
    assert(dll->head->prev == NULL);
    printf("[OK] - Append to empty list\n");

    assert(dllist_append(dll, node2) == true);
    assert(dll->head == node1);
    assert(dll->tail == node2);
    assert(dll->total == 2);
    assert(dll->head->next == node2);
    assert(dll->head->prev == NULL);
    printf("[OK] - Append second element\n");

    assert(dllist_prepend(dll, node3) == true);
    assert(dll->head == node3);
    assert(dll->tail == node2);
    assert(dll->total == 3);
    assert(dll->tail->next == NULL);
    assert(dll->tail->prev == node1);
    printf("[OK] - Prepend third element\n");

    assert(dllist_prepend(dll, node4) == true);
    assert(dll->head == node4);
    assert(dll->tail == node2);
    assert(dll->total == 4);
    assert(dll->tail->next == NULL);
    assert(dll->tail->prev == node1);
    printf("[OK] - Prepend fourth element\n");

    assert(dllist_delete_node(dll, node1) == true);
    assert(dllist_delete_node(dll, node2) == true);
    assert(dllist_delete_node(dll, node3) == true);
    assert(dllist_delete_node(dll, node4) == true);
    printf("[OK] - Prepend fourth element\n");

    assert(dllist_prepend(dll, node5) == true);
    assert(dll->head == node5);
    assert(dll->tail == node5);
    assert(dll->total == 1);
    assert(dll->head->next == NULL);
    assert(dll->head->prev == NULL);
    printf("[OK] - Prepend to empty list\n");

    dllist_destroy(dll);
    printf("[OK] - Append and prepend\n");
}

void assert_dllist_insert_and_delete()
{
    dllist_s *dll = dllist_create();

    int *v1 = malloc(sizeof(int));
    int *v2 = malloc(sizeof(int));
    int *v3 = malloc(sizeof(int));

    *v1 = 1;
    *v2 = 2;
    *v3 = 3;

    dllist_node_s *n1 = dllist_create_node(v1);
    dllist_node_s *n2 = dllist_create_node(v2);
    dllist_node_s *n3 = dllist_create_node(v3);

    assert(dllist_append(dll, n3) == true);
    assert(dllist_insert_before_at(dll, n1, 0) == true);
    assert(dllist_insert_before_at(dll, n2, 1) == true);
    assert(dll->total == 3);
    assert(dll->head == n1);
    assert(dll->head->next == n2);
    assert(dll->tail == n3);
    printf("[OK] - Insert three nodes at\n");

    dllist_delete_at(dll, 1);
    assert(dll->total == 2);
    assert(dll->head->next == dll->tail);
    assert(dll->head == n1);
    assert(dll->tail == n3);
    printf("[OK] - Delete node at middle\n");

    dllist_delete_at(dll, dll->total - 1);
    assert(dll->total == 1);
    assert(dll->head == n1);
    assert(dll->tail == n1);
    printf("[OK] - Delete node at end\n");

    dllist_delete_at(dll, 0);
    assert(dll->total == 0);
    assert(dll->head == NULL);
    assert(dll->tail == NULL);
    printf("[OK] - Delete node at first\n");

    dllist_destroy(dll);
}

void assert_dllist_delete_node()
{
    dllist_s *dll = dllist_create();

    int *v = malloc(sizeof(int));
    *v = 42;
    dllist_node_s *n = dllist_create_node(v);

    dllist_append(dll, n);
    assert(dllist_delete_node(dll, n) == true);
    assert(dll->total == 0);
    assert(dll->head == NULL);
    assert(dll->tail == NULL);
    dllist_destroy(dll);
    printf("[OK] - Delete node by pointer\n");
}

int main()
{
    assert_dllist_create_and_destroy_node();
    assert_dllist_create_and_destroy();
    assert_dllist_append_and_prepend();
    assert_dllist_insert_and_delete();
    assert_dllist_delete_node();

    return EXIT_SUCCESS;
}
