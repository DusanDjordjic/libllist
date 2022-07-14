/*
 * Library created by Dusan Djordjic
 * github: https://github.com/DusanDjordjic
 *
 * This software is free to use and redistribute by anyone
 * */

#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

struct node {
    void*           item;
    int             id;
    struct node*    next;
};

typedef struct node node_t;

typedef void    (*iprint)   ();
typedef void    (*ifree)    (void*);

/* Pass an address of node_t and function that prints an item.
 * */
void print_list(node_t* head, iprint);

/* Prints nodes id
 * */
void print_node_id(node_t* head);

/* First creates a new node and sets the next property to NULL.
 * Sets node id to be the passed id.
 * Sets item property to be the passed item.
 * Finally returns new node.
 * */
node_t* create_node(int id, void* item);

/* Goes to the end of the list and calls create_node passing to it item.
 * Saves new node at the and of the list.
 * */
void add_node_to_end(node_t** head, void* item);

/* Creates new node with passed item. After that sets this node to be a head
 * and sets it's next value to be previos head.
 * */
void add_node_to_end(node_t** head, void* item);

/* For each node until the end calls passed function that frees the item.
 * After freeing the item frees the node itself.
 * */
void free_list(node_t** phead, ifree);

/* Finds a node that has passed id
 * */
node_t* find_node(node_t* head, int id);
#endif
