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
    array = clear_static_array(array, 0);

    /*
        TESTING function insert_tail(struct static_array *array, int data)
    */
    array = insert_tail(array, 2); // case 1
    array = insert_tail(array, 11); // case 2
    array = insert_tail(array, 7); // case 2...
    array = insert_tail(array, 63);
    array = insert_tail(array, -1); // error

    /*
        TESTING function remove_head(struct static_array *array)
    */
    array = remove_head(array); // case 1
    array = remove_head(array); // case 1...
    array = remove_head(array);
    array = remove_head(array); // case 2
    array = remove_head(array); // error

    /*
        TESTING function remove_tail(struct static_array *array)
    */
    array = insert_head(array, 2);
    array = insert_tail(array, 11);
    array = insert_head(array, 7);
    array = insert_tail(array, 63);
    array = remove_tail(array); // case 1
    array = remove_tail(array); // case 1...
    array = remove_tail(array);
    array = remove_tail(array); // case 2
    array = remove_tail(array); // error

    /*
        TESTING function replace_data_at_index(struct static_array *array, int index, int data)
    */
    array = clear_static_array(array, 0);
    array = insert_head(array, 2);
    array = insert_head(array, 11);
    array = insert_head(array, 7);
    array = replace_data_at_index(array, 0, 1);
    array = replace_data_at_index(array, 1, 2);
    array = replace_data_at_index(array, 2, 3);
    array = insert_tail(array, 4);

    array = clear_static_array(array, 0);
    array = insert_tail(array, 2);
    array = insert_tail(array, 3);
    array = insert_head(array, 1);
    array = insert_tail(array, 4);

    return EXIT_SUCCESS;
}