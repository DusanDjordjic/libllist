/*
 * Library created by Dusan Djordjic
 * github: https://github.com/DusanDjordjic
 *
 * This software is free to use and distribute by anyone
 * */

#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

struct node {
    void*           item;
    struct node*    next;
};

typedef struct node node_t;

typedef void    (*print_litem)      ();
typedef void*   (*generate_item)    ();
typedef void    (*free_litem)        (void*);

/* Pass an address of node_t and function that prints an item.
 * */
void print_list(node_t* head, print_litem);

/* First creates a new node and sets the next property to NULL, 
 * Calls the passed function that creates an item and returns a poiter to it.
 * Finally saves returned pointer in the item property.
 * */
node_t* create_node(generate_item);

/* Goes to the end of the list and calls create_node passing to it generate_item function.
 * Saves new node at the and of the list.
 * */
void add_node_to_end(node_t* head, generate_item);


/* For each node until the end calls passed function that frees the item.
 * After freeing the item frees the node itself.
 * */
void free_list(node_t** phead, free_litem);

#endif
