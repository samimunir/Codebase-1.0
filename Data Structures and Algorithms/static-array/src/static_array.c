#include "static_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
        printf("\tpointer: %d\n", array -> pointer);
        printf("\tcapacity: %d\n", array -> capacity);
        printf("\t# elements: %d\n", array -> number_of_elements);
        printf("\t\ttotal memory: %d bytes\n", array -> memory);
        printf("\t\tused memory: %d bytes\n", array -> used_memory);
        printf("\t\tavail memory: %d bytes\n", array -> available_memory);
        printf("\tpayload: %.2f\n", array -> payload);
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
            array -> memory = capacity * sizeof(int);
            array -> used_memory = 0;
            array -> available_memory = array -> memory - array -> used_memory;
            array -> payload = (float) array -> used_memory / (float) array -> memory;
            printf("\tSUCCESS: static_array initialized with capacity[%d].\n", array -> capacity);
            print_static_array_struct(array);
            return array;
        }
    }
}

struct static_array * clear_static_array(struct static_array *array, int format_display) {
    free(array -> array);
    array -> array = (int*) malloc(array -> capacity * sizeof(int));
    array -> pointer = -1;
    array -> number_of_elements = 0;
    array -> used_memory = 0;
    array -> available_memory = array -> memory - array -> used_memory;
    array -> payload = (float) array -> used_memory / (float) array -> memory;
    if (format_display == 0) {
        printf("\nclear_static_array() called -->\n");
        printf("\tSUCCESS: static_array cleared/reset to capacity[%d].\n", array -> capacity);
        print_static_array_struct(array);
    } else if (format_display == 1) {
        printf("\tSUCCESS: static_array cleared/reset to capacity[%d].\n", array -> capacity);
        print_static_array_struct(array);
    } else {
        //
    }
    return array;
}

struct static_array * insert_head(struct static_array *array, int data) {
    printf("\ninsert_head(%d) called -->\n", data);
    if (array -> pointer == -1) {
        array -> pointer++;
        array -> array[0] = data;
        array -> number_of_elements++;
        array -> used_memory = array -> number_of_elements * sizeof(int);
        array -> memory = array -> capacity * sizeof(int);
        array -> available_memory = array -> memory - array -> used_memory;
        array -> payload = (float) array -> used_memory / (float) array -> memory;
    } else {
        if (array -> pointer + 1 == array -> capacity) {
            printf("--<ERROR>-- static_array at full capacity [%d], cannot insert at head.\n", array -> capacity);
        } else {
            if (array -> pointer == 0) {
                array -> pointer++;
                array -> array[array -> pointer] = array -> array[0];
                array -> array[0] = data;
                array -> number_of_elements++;
                array -> used_memory = array -> number_of_elements * sizeof(int);
                array -> memory = array -> capacity * sizeof(int);
                array -> available_memory = array -> memory - array -> used_memory;
                array -> payload = (float) array -> used_memory / (float) array -> memory;
            } else {
                array -> pointer++;
                for (int i = array -> pointer; i >= 0; i--) {
                    array -> array[i + 1] = array -> array[i];
                }
                array -> array[0] = data;
                array -> number_of_elements++;
                array -> used_memory = array -> number_of_elements * sizeof(int);
                array -> memory = array -> capacity * sizeof(int);
                array -> available_memory = array -> memory - array -> used_memory;
                array -> payload = (float) array -> used_memory / (float) array -> memory;
            }
        }
    }
    print_static_array_struct(array);
    return array;
}

struct static_array * remove_head(struct static_array *array) {
    printf("\nremove_head() called -->\n");
    if (array -> pointer == -1) {
        printf("--<ERROR>-- cannot remove from empty/null static array.\n");
    } else {
        printf("Successfully removed %d from the head of static array.\n", array -> array[0]);
        if (array -> pointer == 0) {
            array = clear_static_array(array, 2);
        } else {
            array -> pointer--;
            for (int i = 0; i <= array -> pointer; i++) {
                array -> array[i] = array -> array[i + 1];
            }
            for (int i = array -> pointer + 1; i < array -> capacity; i++) {
                array -> array[i] = 0;
            }
            array -> number_of_elements--;
            array -> used_memory = array -> number_of_elements * sizeof(int);
            array -> memory = array -> capacity * sizeof(int);
            array -> available_memory = array -> memory - array -> used_memory;
            array -> payload = (float) array -> used_memory / (float) array -> memory;
        }
    }
    print_static_array_struct(array);
    return array;
}

struct static_array * insert_tail(struct static_array *array, int data) {
    printf("\ninsert_tail(%d) called -->\n", data);
    if (array -> pointer == -1) {
        array -> pointer++;
        array -> array[0] = data;
        array -> number_of_elements++;
        array -> used_memory = array -> number_of_elements * sizeof(int);
        array -> memory = array -> capacity * sizeof(int);
        array -> available_memory = array -> memory - array -> used_memory;
        array -> payload = (float) array -> used_memory / (float) array -> memory;
    } else {
        if (array -> pointer + 1 == array -> capacity) {
            printf("--<ERROR>-- static_array at full capacity [%d], cannot insert at tail.\n", array -> capacity);
        } else {
            array -> pointer++;
            array -> array[array -> pointer] = data;
            array -> number_of_elements++;
            array -> used_memory = array -> number_of_elements * sizeof(int);
            array -> memory = array -> capacity * sizeof(int);
            array -> available_memory = array -> memory - array -> used_memory;
            array -> payload = (float) array -> used_memory / (float) array -> memory;
        }
    }
    print_static_array_struct(array);
    return array;
}

struct static_array * remove_tail(struct static_array *array) {
    printf("\nremove_tail() called -->\n");
    if (array -> pointer == -1) {
        printf("--<ERROR>-- cannot remove from empty/null static array.\n");
    } else {
        printf("Successfully removed %d from the tail of static array.\n", array -> array[array -> pointer]);
        if (array -> pointer == 0) {
            array = clear_static_array(array, 2);
        } else {
            array -> pointer--;
            array -> array[array -> pointer + 1] = 0;
            array -> number_of_elements--;
            array -> used_memory = array -> number_of_elements * sizeof(int);
            array -> memory = array -> capacity * sizeof(int);
            array -> available_memory = array -> memory - array -> used_memory;
            array -> payload = (float) array -> used_memory / (float) array -> memory;
        }
    }
    print_static_array_struct(array);
    return array;
}

struct static_array * replace_data_at_index(struct static_array *array, int index, int data) {
    printf("\nreplace_data_at_index(%d, %d) called -->\n", index, data);
    if (index < 0 || index >= array -> capacity) {
        printf("--<ERROR>-- cannot replace data[%d] at invalid index[%d].\n", data, index);
    } else {
        array -> array[index] = data;
    }
    print_static_array_struct(array);
    return array;
}