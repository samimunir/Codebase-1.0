/*
    doubly-linked-list data structure & algorithms
    - doubly_linked_list.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} *head, *tail;
int number_of_elements = 0;
int pointer = -1;

bool is_empty() {
    if (head == NULL) {
        return true;
    } else {
        return false;
    }
}

void print_linked_list() {
    if (is_empty()) {
        printf("\tHEAD <-> NULL\n");
    } else {
        struct Node *current_node = head;
        printf("\tHEAD");
        while (current_node != NULL) {
            printf(" <-> %d", current_node -> data);
            current_node = current_node -> next;
        }
        printf(" <-> NULL\n");
    }
}

void print_data_structure_stats() {
    print_linked_list();
    printf("\tnumber_of_elements: %d\n", number_of_elements);
    printf("\tpointer: %d\n", pointer);
}

int main(int argc, char* argv[]) {
    printf("doubly-linked-list\n------------------\n");
    /*
        Testing function printLinkedList()
    */
    print_linked_list();
    /*
        Testing function print_data_structure_stats()
    */
    print_data_structure_stats();

    return EXIT_SUCCESS;
}