#include "linked_list_double.h"

dllist_node_s *dllist_create_node(void *data)
{
    dllist_node_s *n = malloc(sizeof(dllist_node_s));
    if (n == NULL)
    {
        return NULL;
    }
    n->data = data;
    n->next = NULL;
    n->prev = NULL;

    return n;
}

void dllist_destroy_node(dllist_node_s *node)
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

dllist_s *dllist_create()
{
    dllist_s *dll = malloc(sizeof(dllist_s));

    if (dll == NULL)
    {
        return NULL;
    }

    dll->head = NULL;
    dll->tail = NULL;
    dll->total = 0;

    return dll;
}

void dllist_destroy(dllist_s *dll)
{
    if (dll != NULL)
    {
        dllist_node_s *current = dll->head;
        dllist_node_s *next;

        while (current != NULL)
        {
            next = current->next;
            dllist_destroy_node(current);
            current = next;
        }

        free(dll);
    }
}

bool dllist_append(dllist_s *dll, dllist_node_s *node)
{
    if (dll == NULL || node == NULL)
    {
        return false;
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

    return true;
}

bool dllist_prepend(dllist_s *dll, dllist_node_s *node)
{
    if (dll == NULL || node == NULL)
    {
        return false;
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

    return true;
}

bool dllist_insert_before_at(dllist_s *dll, dllist_node_s *node, size_t pos)
{
    if (dll == NULL || node == NULL || pos >= dll->total)
    {
        return false;
    }

    if (pos == 0)
    {
        return dllist_prepend(dll, node);
    }

    dllist_node_s *n = dllist_get_node_at(dll, pos);

    node->next = n;
    node->prev = n->prev;
    node->next->prev = node;
    node->prev->next = node;
    dll->total++;

    return true;
}

dllist_node_s *dllist_get_node_at(dllist_s *dll, size_t pos)
{
    if (dll == NULL || pos >= dll->total)
    {
        return NULL;
    }

    dllist_node_s *n;

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

bool dllist_delete_at(dllist_s *dll, size_t pos)
{
    if (dll == NULL || pos >= dll->total)
    {
        return false;
    }

    dllist_node_s *n = dllist_get_node_at(dll, pos);

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

    dllist_destroy_node(n);
    dll->total--;

    return true;
}

bool dllist_delete_node(dllist_s *dll, dllist_node_s *node)
{
    if (dll == NULL || node == NULL || dll->head == NULL || !dllist_node_in(dll, node))
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

    dllist_destroy_node(node);
    dll->total--;

    return true;
}

bool dllist_node_in(dllist_s *dll, dllist_node_s *node)
{
    if (dll == NULL || dll->head == NULL || node == NULL)
    {
        return false;
    }

    dllist_node_s *tmp = dll->head;

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
