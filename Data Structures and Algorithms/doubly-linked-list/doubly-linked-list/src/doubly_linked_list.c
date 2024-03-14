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

int main(int argc, char* argv[]) {
    printf("doubly-linked-list\n------------------\n");
    return EXIT_SUCCESS;
}