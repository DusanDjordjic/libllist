#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

#define CASTV *(item_t*)
#define CASTP  (item_t*)

void print_item(void* pitem);
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

    print_list(head, print_item);

    node_t* found_node = find_node(head, 3);

    if(found_node == NULL)
    {
        printf("Could not find node with an id of 3\n");
    }
    else
    {
        print_node_id(found_node);
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

void print_item(void* pitem)
{
    item_t* item = CASTP pitem;
    printf("Item value is %d\n", item->value);
}

char compare_item(void* item)
{
    return (CASTP item)->value > 10 ? 0 : -1;
}
