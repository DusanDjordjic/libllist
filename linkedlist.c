#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "linkedlist.h"

void print_list(node_t* head, iprint iprint)
{
    int i = 1;
    while(head != NULL)
    {
        printf("Node id %d\n", head->id);
        iprint(head->item);
        ++i;
        head = head->next;
    }
}

node_t* create_node(int id, igen igen)
{
    node_t* new_node = malloc(sizeof(node_t));
    new_node->id = id;
    new_node->next = NULL;
    new_node->item = igen();
    return new_node;
}

void add_node_to_end(node_t **phead, igen igen)
{
    if(phead == NULL) return;
    if(*phead == NULL)
    {
        *phead = create_node(1, igen);
    }

    node_t* head = *phead;
    
    int next_id = 0;

    if(head->next == NULL)
    {
        next_id = head->id + 1;
        head->next = create_node(next_id, igen);
        return;
    }

    while(head->next != NULL) head = head->next;

    next_id = head->id + 1;
    head->next = create_node(next_id, igen);
}

void free_node(node_t* node, ifree ifree)
{
    ifree(node->item);
    free(node);
}

void free_list(node_t** phead, ifree ifree)
{
    node_t* tmp;
    node_t* head = *phead;
    while(head != NULL)
    {
        tmp = head;
        head = head->next;
        free_node(tmp, ifree);
    }
}

node_t* find_node(node_t* head, icmp icmp) 
{
    while(head != NULL)
    {
        if(icmp(head->item) == 0) return head;
        head = head->next;
    }

    return NULL;
}
