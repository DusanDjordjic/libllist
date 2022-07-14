#include "linkedlist.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void print_list(node_t *head, iprint iprint)
{
    while (head != NULL) {
        print_node_id(head);
        iprint(head->item);
        head = head->next;
    }
}

void print_node_id(node_t* head)
{
    printf("Node id %d\n", head->id);
}

node_t *create_node(int id, void *item)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->id = id;
    new_node->next = NULL;
    new_node->item = item;
    return new_node;
}

void add_node_to_end(node_t **phead, void *item)
{
    if (phead == NULL) return;

    if (*phead == NULL)
    {
        *phead = create_node(1, item);
        return;
    }

    node_t *head = *phead;

    int next_id;

    while (head->next != NULL)
        head = head->next;

    next_id = head->id + 1;
    head->next = create_node(next_id, item);
}

void free_node(node_t *node, ifree ifree)
{
    ifree(node->item);
    free(node);
}

void free_list(node_t **phead, ifree ifree)
{
    node_t *tmp;
    node_t *head = *phead;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free_node(tmp, ifree);
    }
}

node_t *find_node(node_t *head, int id)
{
    while(head != NULL)
    {
        if(head->id == id)
            return head;

        head = head->next;
    }
    return NULL;
}
