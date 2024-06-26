struct static_array {
    int *array;
    int pointer;
    int capacity;
    int number_of_elements;
    int memory;
    int used_memory;
    int available_memory;
    float payload;
};

struct static_array * init_static_array(int capacity);

struct static_array * clear_static_array(struct static_array *array, int format_display);

struct static_array * insert_head(struct static_array *array, int data);

struct static_array * remove_head(struct static_array *array);

struct static_array * insert_tail(struct static_array *array, int data);

struct static_array * remove_tail(struct static_array *array);

struct static_array * replace_data_at_index(struct static_array *array, int index, int data);