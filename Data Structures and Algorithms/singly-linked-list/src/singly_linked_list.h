struct linked_list_node {
    int data;
    struct linked_list_node *next;
};

#define MAX_MEMORY 4096

struct singly_linked_list {
    struct linked_list_node *head;
    int number_of_elements;
    int linked_list_node_memory;
    int memory;
    int used_memory;
    int available_memory;
    float payload;
};

struct singly_linked_list * initialize_linked_list();

struct singly_linked_list * insert_head(struct singly_linked_list *linked_list, int data);