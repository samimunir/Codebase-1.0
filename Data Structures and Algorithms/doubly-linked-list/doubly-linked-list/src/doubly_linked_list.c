/*
    doubly-linked-list data structure & algorithms
    - doubly_linked_list.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} *head, *tail;

int main(int argc, char* argv[]) {
    printf("doubly-linked-list\n------------------\n");
    return EXIT_SUCCESS;
}