struct linked_list_node {
    int data;
    struct linked_list_node *next;
};

struct singly_linked_list {
    struct linked_list_node *head;
    int number_of_elements;
    int memory;
    int used_memory;
    int available_memory;
    float payload;
};

struct singly_linked_list * initialize_linked_list();