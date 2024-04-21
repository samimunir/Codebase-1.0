struct linkedlist_node {
    int data;
    struct linkedlist_node *next;
};

struct singly_linked_list {
    struct linkedlist_node *head;
    int number_of_elements;
    int memory;
    int used_memory;
    int available_memory;
    float payload;
};