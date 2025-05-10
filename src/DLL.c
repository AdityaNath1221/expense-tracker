#include <stdio.h>
#include <stdlib.h>
#include "DLL.h"

node* create_node(int data){
    node* newnode=(node*)malloc(sizeof(node));
    
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;

    return newnode;
}

void initDLL(DLL* list){
    list->head = NULL;
    list->tail = NULL;
    
    return;
}

void insert_end(DLL* list, int data){
    node* newnode = create_node(data);
    
    if(list->head == NULL){             //if list is empty, then the head and the tail 
        list->head = newnode;           //both will point to newnode.
        list->tail = newnode;
        return;
    }

    list->tail->next = newnode;
    newnode->prev = list->tail;
    list->tail = newnode;

    return;
}

void free_all(DLL* list){
    node* current = list->head;
    node* next;

    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
    list->tail = NULL;

    return;
}