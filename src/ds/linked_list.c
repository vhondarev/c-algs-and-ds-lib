#include "linked_list.h"

l_list_node_s *l_list_create_node(void *data)
{
    l_list_node_s *node = malloc(sizeof(l_list_node_s));
    if (node == NULL)
    {
        return NULL;
    }

    node->data = data;
    node->next = NULL;

    return node;
}

void l_list_destroy_node(l_list_node_s *node)
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

l_list_s *l_list_create()
{
    l_list_s *ll = malloc(sizeof(l_list_s));
    if (ll == NULL)
    {
        return NULL;
    }

    ll->head = NULL;
    ll->tail = NULL;
    ll->total = 0;

    return ll;
}

void l_list_destroy(l_list_s *ll)
{
    if (ll == NULL)
    {
        return;
    }

    l_list_node_s *current = ll->head;

    while (current != NULL)
    {
        l_list_node_s *next = current->next;
        l_list_destroy_node(current);
        current = next;
    }

    free(ll);
}

bool l_list_append(l_list_s *ll, l_list_node_s *node)
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

bool l_list_prepend(l_list_s *ll, l_list_node_s *node)
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

bool l_list_insert_before_at(l_list_s *ll, l_list_node_s *node, size_t pos)
{
    if (ll == NULL || node == NULL || pos > ll->total)
    {
        return false;
    }

    else if (pos == 0 || ll->head == NULL)
    {
        return l_list_prepend(ll, node);
    }
    else
    {
        l_list_node_s *prev = ll->head;
        l_list_node_s *next = prev->next;

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

bool l_list_delete_at(l_list_s *ll, size_t pos)
{
    if (ll == NULL || ll->head == NULL || pos >= ll->total)
    {
        return false;
    }

    l_list_node_s *tmp;

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
        l_list_node_s *prev = ll->head;

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

    l_list_destroy_node(tmp);
    ll->total--;

    return true;
}

l_list_node_s *l_list_get_node_at(l_list_s *ll, size_t pos)
{
    if (ll == NULL || ll->head == NULL || pos >= ll->total || pos < 0)
    {
        return NULL;
    }

    l_list_node_s *node = ll->head;

    for (size_t i = 0; i < pos; i++)
    {
        node = node->next;
    }

    return node;
}
