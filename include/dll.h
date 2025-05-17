#ifndef DLL_H
#define DLL_H

#include "expense.h"

typedef struct node{
    struct node* prev;
    expense data;
    struct node* next;
}node;

node* create_node(Expense e);
void insert_end(node** head, expense e);
void print_all_node(node** head);
void free_list(node* head);

#endif DLL_H