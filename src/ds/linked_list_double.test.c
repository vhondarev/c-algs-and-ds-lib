#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list_double.h"

void assert_dl_list_create_and_destroy_node()
{
    int *value = malloc(sizeof(int));
    *value = 123;

    dl_list_node_s *dl_list_node = dl_list_create_node(value);
    assert(dl_list_node != NULL);
    assert(dl_list_node->data == value);
    assert(dl_list_node->next == NULL);
    assert(dl_list_node->prev == NULL);
    dl_list_destroy_node(dl_list_node);
    printf("[OK] - Dll created and destroyed node with valid data\n");

    dl_list_node_s *null_data_node = dl_list_create_node(NULL);
    assert(null_data_node != NULL);
    assert(null_data_node->data == NULL);
    assert(null_data_node->next == NULL);
    dl_list_destroy_node(null_data_node);
    printf("[OK] - Dll created and destroyed node with NULL data\n");

    dl_list_destroy_node(NULL);
    printf("[OK] - Dll destroying NULL node\n");
}

void assert_dl_list_create_and_destroy()
{
    dl_list_s *dll = dl_list_create();
    assert(dll->head == NULL);
    assert(dll->tail == NULL);
    assert(dll->total == 0);
    printf("[OK] - Dll created empty\n");

    dl_list_destroy(dll);
    printf("[OK] - Dll destroyed empty\n");
}

void assert_dl_list_append_and_prepend()
{
    dl_list_s *dll = dl_list_create();
    assert(dll != NULL);

    int *val1 = malloc(sizeof(int));
    int *val2 = malloc(sizeof(int));
    *val1 = 10;
    *val2 = 20;

    dl_list_node_s *node1 = dl_list_create_node(val1);
    dl_list_node_s *node2 = dl_list_create_node(val2);

    int pos1 = dl_list_append(dll, node1);
    assert(pos1 == 0);
    assert(dll->head == node1);
    assert(dll->tail == node1);
    assert(dll->total == 1);

    int pos2 = dl_list_prepend(dll, node2);
    assert(pos2 == 0);
    assert(dll->head == node2);
    assert(dll->tail == node1);
    assert(dll->total == 2);

    assert(dll->head->next == node1);
    assert(dll->tail->prev == node2);

    dl_list_destroy(dll);
    printf("[OK] - Dll append and prepend\n");
}

void assert_dl_list_insert_and_delete()
{
    dl_list_s *dll = dl_list_create();

    int *v1 = malloc(sizeof(int));
    *v1 = 1;
    int *v2 = malloc(sizeof(int));
    *v2 = 2;
    int *v3 = malloc(sizeof(int));
    *v3 = 3;

    dl_list_node_s *n1 = dl_list_create_node(v1);
    dl_list_node_s *n2 = dl_list_create_node(v2);
    dl_list_node_s *n3 = dl_list_create_node(v3);

    dl_list_append(dll, n1);
    dl_list_append(dll, n3);
    dl_list_insert_before_at(dll, n2, 1);

    assert(dll->total == 3);
    assert(dll->head->data == v1);
    assert(dll->head->next->data == v2);
    assert(dll->tail->data == v3);

    dl_list_delete_at(dll, 1);
    assert(dll->total == 2);
    assert(dll->head->next == dll->tail);
    assert(dll->head->data == v1);
    assert(dll->tail->data == v3);

    dl_list_destroy(dll);
    printf("[OK] - Dll insert before and delete at\n");
}

void assert_dl_list_delete_node()
{
    dl_list_s *dll = dl_list_create();

    int *v = malloc(sizeof(int));
    *v = 42;
    dl_list_node_s *n = dl_list_create_node(v);

    dl_list_append(dll, n);
    assert(dll->total == 1);
    assert(dl_list_delete_node(dll, n) == true);
    assert(dll->total == 0);
    assert(dll->head == NULL);
    assert(dll->tail == NULL);

    dl_list_destroy(dll);
    printf("[OK] - Dll delete node by pointer\n");
}

int main()
{
    assert_dl_list_create_and_destroy_node();
    assert_dl_list_create_and_destroy();
    assert_dl_list_append_and_prepend();
    assert_dl_list_insert_and_delete();
    assert_dl_list_delete_node();

    return EXIT_SUCCESS;
}
