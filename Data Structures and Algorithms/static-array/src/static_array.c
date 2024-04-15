#include "static_array.h"
#include <stdio.h>
#include <stdlib.h>

void print_static_array(int *array, int capacity) {
    printf("[ ");
    for (int i = 0; i < capacity; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

void print_static_array_struct(struct static_array *array) {
    if (array == NULL) {
        printf("static_array[] is NULL/not initialized.\n");
        return;
    } else {
        printf("\tstatic_array: ");
        print_static_array(array -> array, array -> capacity);
        printf("\tcapacity: %d\n", array -> capacity);
        printf("\t# elements: %d\n", array -> number_of_elements);
        printf("\ttotal memory: %d bytes\n", array -> memory);
        printf("\tused memory: %d bytes\n", array -> used_memory);
        printf("\tavail memory: %d bytes\n", array -> available_memory);
    }
}

struct static_array * init_static_array(int capacity) {
    if (capacity <= 0) {
        printf("\ninit_static_array(%d) called -->\n", capacity);
        printf("--<ERROR>-- initialization unable with capacity[%d].\n", capacity);
        return NULL;
    } else {
        printf("\ninit_static_array(%d) called -->\n", capacity);
        struct static_array *array = (struct static_array *) malloc(sizeof(struct static_array));
        if (array == NULL) {
            printf("\t--<ERROR>-- failed to allocate memory for static_array with capacity[%d].\n", capacity);
            return NULL;
        } else {
            array -> array = (int*) malloc(capacity * sizeof(int));
            array -> pointer = -1;
            array -> capacity = capacity;
            array -> memory = sizeof(array -> array);
            array -> used_memory = 0;
            array -> available_memory = array -> memory - array -> used_memory;
            printf("\tSUCCESS: static_array initialized with capacity[%d].\n", capacity);
            print_static_array_struct(array);
            return array;
        }
    }
}