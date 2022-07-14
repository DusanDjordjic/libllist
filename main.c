#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

#define CASTV *(item_t*)
#define CASTP  (item_t*)

void print_node(node_t* node);
void* create_item();
void free_item(void* item);
char compare_item(void* item);

struct item {
    int value;
};
typedef struct item item_t;

int main(int argc, char* argv[])
{
    printf("Test start\n");
    node_t* head = NULL;
    
    void* new_item1 = create_item();
    void* new_item2 = create_item();
    void* new_item3 = create_item();

    head = create_node(1, new_item1); 
    add_node_to_end(&head, new_item2);
    add_node_to_end(&head, new_item3);
    print_list(head, print_node);

    node_t* found_node = find_node_by_id(head, 10);

    if(found_node == NULL)
    {
        printf("Could not find node with an id of 10\n");
    }
    else
    {
        print_node(found_node);
    }

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

void print_node(node_t* node)
{
    printf("%d : Item value is %d\n", node->id, (CASTP node->item)->value);
}

