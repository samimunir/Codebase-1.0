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

void insert_at_head(int data) {
    printf("\ninsert_at_head(%d) called...\n", data);
    if (is_empty()) {
        head = (struct Node*) malloc(sizeof(struct Node));
        head -> data = data;
        head -> next = NULL;
        head -> prev = NULL;
        tail = head;
        number_of_elements++;
        pointer++;
    } else {
        if (head -> next == NULL) {
            struct Node *new_head_node = (struct Node*) malloc(sizeof(struct Node));
            new_head_node -> data = data;
            new_head_node -> next = head;
            new_head_node -> prev = NULL;
            head = new_head_node;
            head -> prev = new_head_node;
            tail = tail -> next;
            number_of_elements++;
            pointer++;
        } else {
            struct Node *new_head_node = (struct Node*) malloc(sizeof(struct Node));
            new_head_node -> data = data;
            new_head_node -> next = head;
            new_head_node -> prev = NULL;
            head = new_head_node;
            head -> prev = new_head_node;
            number_of_elements++;
            pointer++;
        }
    }
    print_data_structure_stats();
}

int main(int argc, char* argv[]) {
    printf("doubly-linked-list\n------------------\n");
    /*
        Testing function printLinkedList()
    */
    // print_linked_list();
    /*
        Testing function print_data_structure_stats()
    */
    print_data_structure_stats();
    /*
        Testing function insert_at_head()
    */
    insert_at_head(2);
    insert_at_head(11);
    insert_at_head(7);

    return EXIT_SUCCESS;
}