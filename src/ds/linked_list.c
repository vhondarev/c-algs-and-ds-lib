#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

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

            if (current->data != NULL)
            {
                free(current->data);
                current->data = NULL;
            }

            free(current);
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

// TODO
// Inserting a node at a specific index.
// Deleting a node by value or by index.
// Searching for a node.
// Getting the element at a specific index.
