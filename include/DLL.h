#ifndef DLL_h
#def DLL_h

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
} node;

node* create_node();
void insert_end();
void delete_node();
void print_forward();
void print_backward();
void free_all();

#endif