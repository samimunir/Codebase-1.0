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

    return EXIT_SUCCESS;
}