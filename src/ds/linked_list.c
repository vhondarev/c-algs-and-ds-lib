#include "linked_list.h"

ll_node_s *ll_create_node(void *data)
{
    ll_node_s *node = malloc(sizeof(ll_node_s));
    if (node == NULL)
    {
        return NULL;
    }

    node->data = data;
    node->next = NULL;

    return node;
}

void ll_destroy_node(ll_node_s *node)
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

ll_s *ll_create()
{
    ll_s *ll = malloc(sizeof(ll_s));
    if (ll == NULL)
    {
        return NULL;
    }

    ll->head = NULL;
    ll->tail = NULL;
    ll->total = 0;

    return ll;
}

void ll_destroy(ll_s *ll)
{
    if (ll == NULL)
    {
        return;
    }

    if (ll->head != NULL)
    {
        ll_node_s *current = ll->head;
        ll_node_s *next;

        while (current != NULL)
        {
            next = current->next;
            ll_destroy_node(current);
            current = next;
        }
    }
    free(ll);

    return;
}

bool ll_append(ll_s *ll, ll_node_s *node)
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
        ll_node_s *last = ll->tail;
        last->next = node;
        ll->tail = node;
        ll->total++;

        return true;
    }
}

bool ll_prepend(ll_s *ll, ll_node_s *node)
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

bool ll_insert(ll_s *ll, ll_node_s *node, size_t pos)
{
    if (ll == NULL || node == NULL || pos < 0 || pos > ll->total)
    {
        return false;
    }
    else if (pos == 0 || ll->head == NULL)
    {
        return ll_prepend(ll, node);
    }
    else if (pos == ll->total)
    {
        return ll_append(ll, node);
    }
    else
    {
        ll_node_s *prev = ll->head;
        ll_node_s *next = prev->next;

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

bool ll_delete(ll_s *ll, size_t pos)
{
    if (ll == NULL || ll->head == NULL || pos < 0 || pos >= ll->total)
    {
        return false;
    }

    ll_node_s *tmp;

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
        ll_node_s *prev = ll->head;

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

    ll_destroy_node(tmp);
    ll->total--;

    return true;
}

ll_node_s *ll_get_node_at(ll_s *ll, size_t pos)
{
    if (ll == NULL || ll->head == NULL || pos >= ll->total || pos < 0)
    {
        return NULL;
    }

    ll_node_s *node = ll->head;

    for (size_t i = 0; i < pos; i++)
    {
        node = node->next;
    }

    return node;
}
