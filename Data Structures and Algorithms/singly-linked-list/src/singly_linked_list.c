#include "singly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_linked_list(struct linked_list_node *head) {
    if (head == NULL) {
        printf("HEAD is either NULL or not initialized.\n");
        return;
    } else if (head -> next == NULL) {
        printf("HEAD -> %d -> NULL\n", head -> data);
        return;
    } else {
        printf("HEAD -> ");
        struct linked_list_node *current_node = head;
        while (current_node != NULL) {
            printf("%d -> ", current_node -> data);
            current_node = current_node -> next;
        }
        printf("NULL\n");
        return;
    }
}

void print_linked_list_struct(struct singly_linked_list *linked_list) {
    if (linked_list == NULL) {
        printf("linked_list is NULL/not initialized.\n");
        return;
    }
    printf("\tlinked_list: ");
    print_linked_list(linked_list -> head);
    printf("\t# elements: %d\n", linked_list -> number_of_elements);
    printf("\tbytes/(1) node: %d bytes\n", linked_list -> linked_list_node_memory);
    printf("\t\ttotal memory: %d bytes\n", linked_list -> memory);
    printf("\t\tused memory: %d bytes\n", linked_list -> used_memory);
    printf("\t\tavail memory: %d bytes\n", linked_list -> available_memory);
    printf("\tpayload: %.2f\n", linked_list -> payload);
    return;
}

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
    linked_list -> linked_list_node_memory = sizeof(struct linked_list_node);
    linked_list -> number_of_elements = 0;
    linked_list -> memory = MAX_MEMORY;
    linked_list -> used_memory = linked_list -> number_of_elements * linked_list -> linked_list_node_memory;
    linked_list -> available_memory = linked_list -> memory - linked_list -> used_memory;
    linked_list -> payload = 0.0;

    printf("\tlinked_list successfully initialzed.\n");
    print_linked_list_struct(linked_list);
    
    return linked_list;
}