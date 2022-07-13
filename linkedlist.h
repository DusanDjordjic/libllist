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
typedef void*   (*igen)     ();
typedef void    (*ifree)    (void*);
typedef char    (*icmp)     (void*);

/* Pass an address of node_t and function that prints an item.
 * */
void print_list(node_t* head, iprint);

/* First creates a new node and sets the next property to NULL, 
 * Calls the passed function that creates an item and returns a poiter to it.
 * Finally saves returned pointer in the item property.
 * */
node_t* create_node(int id, igen);

/* Goes to the end of the list and calls create_node passing to it generate_item function.
 * Saves new node at the and of the list.
 * */
void add_node_to_end(node_t** head, igen);


/* For each node until the end calls passed function that frees the item.
 * After freeing the item frees the node itself.
 * */
void free_list(node_t** phead, ifree);

/* For each node calls passed function and passes item to it.
 * If compare function returns 0, it returns pointer to node containing that item.
 * If the item was not found returns NULL
 * */
node_t* find_node(node_t* head, icmp);
#endif
