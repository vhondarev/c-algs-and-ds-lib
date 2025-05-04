#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

node_s *create_node(void *data)
{
    node_s *node = malloc(sizeof(node_s));
    node->data = data;
    node->next = NULL;

    return node;
}

void destroy_node(node_s *node)
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

linked_list_s *linked_list_create()
{
    linked_list_s *ll = malloc(sizeof(linked_list_s));
    if (ll == NULL)
    {
        return NULL;
    }

    ll->head = NULL;
    ll->tail = NULL;
    ll->total = 0;

    return ll;
}

void linked_list_destroy(linked_list_s *ll)
{
    if (ll == NULL)
    {
        return;
    }

    if (ll->head != NULL)
    {
        node_s *current = ll->head;
        node_s *next;

        while (current != NULL)
        {
            next = current->next;
            destroy_node(current);
            current = next;
        }
    }
    free(ll);

    return;
}

bool linked_list_append(linked_list_s *ll, node_s *node)
{
    if (ll == NULL || node == NULL)
    {
        return false;
    }
    else if (ll->head == NULL)
    {
        ll->head = node;
        ll->tail = node;
        ll->total++;

        return true;
    }
    else
    {
        node_s *last = ll->tail;
        last->next = node;
        ll->tail = node;
        ll->total++;

        return true;
    }
}

bool linked_list_prepend(linked_list_s *ll, node_s *node)
{
    if (ll == NULL || node == NULL)
    {
        return false;
    }
    else if (ll->head == NULL)
    {
        ll->head = node;
        ll->tail = node;
        ll->total++;

        return true;
    }
    else
    {
        node->next = ll->head;
        ll->head = node;
        ll->total++;
        return true;
    }
}

bool linked_list_insert(linked_list_s *ll, node_s *node, int pos)
{
    if (ll == NULL || node == NULL || pos < 0 || pos > ll->total)
    {
        return false;
    }
    else if (pos == 0 || ll->head == NULL)
    {
        return linked_list_prepend(ll, node);
    }
    else if (pos == ll->total)
    {
        return linked_list_append(ll, node);
    }
    else
    {
        node_s *prev = ll->head;
        node_s *next = prev->next;

        for (int i = 1; i < pos; i++)
        {
            prev = prev->next;
            next = next->next;
        }

        prev->next = node;
        node->next = next;
        ll->total++;

        return true;
    }
}

bool linked_list_delete(linked_list_s *ll, int pos)
{
    if (ll == NULL || ll->head == NULL || pos < 0 || pos >= ll->total)
    {
        return false;
    }

    node_s *tmp;

    if (pos == 0)
    {
        tmp = ll->head;
        ll->head = tmp->next;

        if (ll->total == 1)
        {
            ll->tail = NULL;
        }
    }
    else
    {
        node_s *prev = ll->head;

        for (int i = 1; i < pos; i++)
        {
            prev = prev->next;
        }

        tmp = prev->next;
        prev->next = tmp->next;

        if (tmp == ll->tail)
        {
            ll->tail = prev;
        }
    }

    destroy_node(tmp);
    ll->total--;

    return true;
}

node_s *linked_list_get_node(linked_list_s *ll, int pos)
{
    if (ll == NULL || ll->head == NULL || pos >= ll->total || pos < 0)
    {
        return NULL;
    }

    node_s *node = ll->head;

    for (int i = 0; i < pos; i++)
    {
        node = node->next;
    }

    return node;
}
