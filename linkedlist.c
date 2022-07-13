#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

void print_list(node_t* head, print_litem print_item)
{
    int i = 1;
    while(head != NULL)
    {
        print_item(head->item);
        ++i;
        head = head->next;
    }
}

node_t* create_node(generate_item gen)
{
    node_t* new_node = malloc(sizeof(node_t));
    new_node->next = NULL;
    new_node->item = gen();
    return new_node;
}

void add_node_to_end(node_t *head, generate_item gen)
{
    if(head == NULL) return;

    if(head->next == NULL)
    {
        head->next = create_node(gen);
        return;
    }

    while(head->next != NULL) head = head->next;

    head->next = create_node(gen);
}

void free_node(node_t* node, free_litem fr)
{
    fr(node->item);
    free(node);
}

void free_list(node_t** phead, free_litem fr)
{
    node_t* tmp;
    node_t* head = *phead;
    while(head != NULL)
    {
        tmp = head;
        head = head->next;
        free_node(tmp, fr);
    }
}
