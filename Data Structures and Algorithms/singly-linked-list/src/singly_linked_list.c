#include "singly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct singly_linked_list * initialize_linked_list() {
    printf("\ninitialize_linked_list() called -->\n");
    struct linked_list_node *head = (struct linked_list_node *) malloc(sizeof(struct linked_list_node));
    if (head == NULL) {
        printf("\t--<ERROR>-- failed to allocate memory for head node.\n");
        return NULL;
    }
    head -> next = NULL;
    struct singly_linked_list *linked_list = (struct singly_linked_list *) malloc(sizeof(struct singly_linked_list));
    if (linked_list == NULL) {
        printf("\t--<ERROR>-- failed to allocate memory for linked list structure.\n");
        return NULL;
    }
    linked_list -> head = head;
    linked_list -> number_of_elements = 0;
    linked_list -> memory = 0;
    linked_list -> available_memory = 0;
    linked_list -> used_memory = 0;
    linked_list -> payload = 0.0;

    printf("\tlinked list successfully initialzed.\n");
    
    return linked_list;
}