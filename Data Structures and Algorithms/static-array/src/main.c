/*
    Sami Munir
    April 15th, 2024
    Codebase 1.0
        Data Structures & Algorithms
            Static Arrays
            - main.c
*/

#include "static_array.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    printf("static-array (implementation in C)\n");

    /*
        TESTING function init_static_array(int capacity)
    */
    struct static_array *array = init_static_array(4);

    /*
        TESTING function insert_head(struct static_array *array, int data)
    */
    array = insert_head(array, 2); // case 1
    array = insert_head(array, 11); // case 2
    array = insert_head(array, 7); // case 3
    array = insert_head(array, 63); // case 3...
    array = insert_head(array, -1); // error

    /*
        TESTING function clear_static_array(struct static_array *array)
    */
    array = clear_static_array(array);

    /*
        TESTING function insert_tail(struct static_array *array, int data)
    */
    array = insert_tail(array, 2); // case 1
    array = insert_tail(array, 11); // case 2
    array = insert_tail(array, 7); // case 2...
    array = insert_tail(array, 63);
    array = insert_tail(array, -1); // error

    return EXIT_SUCCESS;
}