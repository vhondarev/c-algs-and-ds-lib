#include "linked_list_double.h"

dl_list_node_s *dl_list_create_node(void *data)
{
    dl_list_node_s *n = malloc(sizeof(dl_list_node_s));
    if (n == NULL)
    {
        return NULL;
    }
    n->data = data;
    n->next = NULL;
    n->prev = NULL;

    return n;
}

void dl_list_destroy_node(dl_list_node_s *node)
{
    if (node == NULL)
    {
        return;
    }
    else if (node->data != NULL)
    {
        free(node->data);
        node->data = NULL;
    }

    free(node);
}

dl_list_s *dl_list_create()
{
    dl_list_s *dll = malloc(sizeof(dl_list_s));

    if (dll == NULL)
    {
        return NULL;
    }

    dll->head = NULL;
    dll->tail = NULL;
    dll->total = 0;

    return dll;
}

void dl_list_destroy(dl_list_s *dll)
{
    if (dll != NULL)
    {
        dl_list_node_s *current = dll->head;
        dl_list_node_s *next;

        while (current != NULL)
        {
            next = current->next;
            dl_list_destroy_node(current);
            current = next;
        }

        free(dll);
    }
}

int dl_list_append(dl_list_s *dll, dl_list_node_s *node)
{
    if (dll == NULL || node == NULL)
    {
        return -1;
    }

    if (dll->head == NULL)
    {
        dll->head = node;
        dll->tail = node;
    }
    else
    {
        node->prev = dll->tail;
        node->prev->next = node;
        dll->tail = node;
    }

    dll->total++;

    return dll->total - 1;
}

int dl_list_prepend(dl_list_s *dll, dl_list_node_s *node)
{
    if (dll == NULL || node == NULL)
    {
        return -1;
    }

    if (dll->head == NULL)
    {
        dll->head = node;
        dll->tail = node;
    }
    else
    {
        node->next = dll->head;
        node->next->prev = node;
        dll->head = node;
    }

    dll->total++;

    return 0;
}

bool dl_list_insert_before_at(dl_list_s *dll, dl_list_node_s *node, size_t pos)
{
    if (dll == NULL || node == NULL || pos >= dll->total)
    {
        return false;
    }

    if (pos == 0)
    {
        return dl_list_prepend(dll, node) != -1;
    }

    dl_list_node_s *n = dl_list_get_node_at(dll, pos);

    node->next = n;
    node->prev = n->prev;
    node->next->prev = node;
    node->prev->next = node;
    dll->total++;

    return true;
}

dl_list_node_s *dl_list_get_node_at(dl_list_s *dll, size_t pos)
{
    if (dll == NULL || pos >= dll->total)
    {
        return NULL;
    }

    dl_list_node_s *n;

    if (pos < dll->total / 2)
    {
        n = dll->head;
        for (size_t i = 0; i < pos; i++)
        {
            n = n->next;
        }
    }
    else
    {
        n = dll->tail;
        for (size_t i = dll->total - 1; i > pos; --i)
        {
            n = n->prev;
        }
    }

    return n;
}

bool dl_list_delete_at(dl_list_s *dll, size_t pos)
{
    if (dll == NULL || pos >= dll->total)
    {
        return false;
    }

    dl_list_node_s *n = dl_list_get_node_at(dll, pos);

    if (n->prev)
    {
        n->prev->next = n->next;
    }
    else
    {
        dll->head = n->next;
    }

    if (n->next)
    {
        n->next->prev = n->prev;
    }
    else
    {
        dll->tail = n->prev;
    }

    dl_list_destroy_node(n);
    dll->total--;

    return true;
}

bool dl_list_delete_node(dl_list_s *dll, dl_list_node_s *node)
{
    if (dll == NULL || node == NULL || dll->head == NULL || !dl_list_node_in(dll, node))
    {
        return false;
    }

    if (node->prev)
    {
        node->prev->next = node->next;
    }
    else
    {
        dll->head = node->next;
    }

    if (node->next)
    {
        node->next->prev = node->prev;
    }
    else
    {
        dll->tail = node->prev;
    }

    dl_list_destroy_node(node);
    dll->total--;

    return true;
}

bool dl_list_node_in(dl_list_s *dll, dl_list_node_s *node)
{
    if (dll == NULL || dll->head == NULL || node == NULL)
    {
        return false;
    }

    dl_list_node_s *tmp = dll->head;

    while (tmp != NULL)
    {
        if (tmp == node)
        {
            return true;
        }
        tmp = tmp->next;
    }

    return false;
}
