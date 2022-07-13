#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

#define CASTV *(item_t*)
#define CASTP  (item_t*)

void print_item(void* pitem);
void* create_item();
void free_item(void* item);

struct item {
    int value;
};
typedef struct item item_t;

int main(int argc, char* argv[])
{
    printf("Test start\n");
    node_t* head = NULL;
    

    head = create_node(create_item); 

    print_list(head, print_item);

    printf("Adding node to end\n");
    add_node_to_end(head, create_item);

    printf("Adding node to end\n");
    add_node_to_end(head, create_item);

    print_list(head, print_item);

    free_list(&head, free_item);
    return 0;
}

void free_item(void* item)
{
    free((item_t*)item);
}

void* create_item()
{
    item_t* new_item = malloc(sizeof(item_t));
    int val;
    printf("Enter a new number: ");
    scanf("%d", &val);
    new_item->value = val;

    return new_item;
}

void print_item(void* pitem)
{
    item_t* item = CASTP pitem;
    printf("Item value is %d\n", item->value);
}
