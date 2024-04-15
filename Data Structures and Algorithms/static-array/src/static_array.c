#include "static_array.h"
#include <stdio.h>
#include <stdlib.h>

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
            array -> capacity = capacity;
            array -> memory = sizeof(array -> array);
            array -> used_memory = 0;
            array -> available_memory = array -> memory - array -> used_memory;
            printf("\tSUCCESS: static_array initialized with capacity[%d].\n", capacity);
            return array;
        }
    }
}