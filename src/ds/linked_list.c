#include "linked_list.h"

llist_node_s *llist_create_node(void *data)
{
    llist_node_s *node = malloc(sizeof(llist_node_s));
    if (node == NULL)
    {
        return NULL;
    }

    node->data = data;
    node->next = NULL;

    return node;
}

void llist_destroy_node(llist_node_s *node)
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

llist_s *llist_create()
{
    llist_s *ll = malloc(sizeof(llist_s));
    if (ll == NULL)
    {
        return NULL;
    }

    ll->head = NULL;
    ll->tail = NULL;
    ll->total = 0;

    return ll;
}

void llist_destroy(llist_s *ll)
{
    if (ll == NULL)
    {
        return;
    }

    llist_node_s *current = ll->head;

    while (current != NULL)
    {
        llist_node_s *next = current->next;
        llist_destroy_node(current);
        current = next;
    }

    free(ll);
}

bool llist_append(llist_s *ll, llist_node_s *node)
{
    if (ll == NULL || node == NULL)
        return false;

    if (ll->head == NULL)
    {
        ll->head = ll->tail = node;
    }
    else
    {
        ll->tail->next = node;
        ll->tail = node;
    }

    ll->total++;
    return true;
}

bool llist_prepend(llist_s *ll, llist_node_s *node)
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

bool llist_insert_before_at(llist_s *ll, llist_node_s *node, size_t pos)
{
    if (ll == NULL || node == NULL || pos > ll->total)
    {
        return false;
    }

    else if (pos == 0)
    {
        return llist_prepend(ll, node);
    }
    else
    {
        llist_node_s *prev = ll->head;
        llist_node_s *next = prev->next;

        for (size_t i = 1; i < pos; i++)
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

bool llist_delete_at(llist_s *ll, size_t pos)
{
    if (ll == NULL || ll->head == NULL || pos >= ll->total)
    {
        return false;
    }

    llist_node_s *tmp;

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
        llist_node_s *prev = ll->head;

        for (size_t i = 1; i < pos; i++)
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

    llist_destroy_node(tmp);
    ll->total--;

    return true;
}

llist_node_s *llist_get_node_at(llist_s *ll, size_t pos)
{
    if (ll == NULL || ll->head == NULL || pos >= ll->total)
    {
        return NULL;
    }

    llist_node_s *node = ll->head;

    for (size_t i = 0; i < pos; i++)
    {
        node = node->next;
    }

    return node;
}
