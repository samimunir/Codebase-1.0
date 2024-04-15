struct static_array {
    int *array;
    int pointer;
    int capacity;
    int number_of_elements;
    int memory;
    int used_memory;
    int available_memory;
};

struct static_array * init_static_array(int capacity);