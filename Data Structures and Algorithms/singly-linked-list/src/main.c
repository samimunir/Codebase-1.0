/*
    Sami Munir
    April 20th, 2024
    Codebase 1.0
        Data Structures & Algorithms
            Singly Linked-lists
            - main.c
*/

#include "singly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    printf("singly-linked-list (implementation in C)\n");

    /*
        TESTING function initialize_linked_list()
    */
    struct singly_linked_list *linked_list = initialize_linked_list();

    /*
        TESTING function insert_head()
    */
    linked_list = insert_head(linked_list, 2);
    linked_list = insert_head(linked_list, 11);
    linked_list = insert_head(linked_list, 7);
    linked_list = insert_head(linked_list, 63);
    
    return EXIT_SUCCESS;
}