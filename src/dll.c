#include <stdio.h>
#include <stdlib.h>
#include "expense.h"
#include "dll.h"

node* create_node(expense e){
    node* new_node = (node*) malloc(sizeof(node));
    if(new_node == NULL){
        printf("Memory allocation failed.");
        return NULL;
    }
    
    new_node->prev = NULL;
    new_node->data = e;
    new_node->next = NULL;

    return new_node;
}

void insert_end(node** head, expense e){
    node* new_node = create_node(e);
    if(new_node==NULL){
        return;
    }

    if(*head ==NULL){
        *head = new_node;
        return;
    }

    node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->prev = temp;
    return;
}

void print_all_node(node* head){
    node* temp = head;
    if (temp==NULL) return;
    while(temp->next!=NULL){
        print_expense(temp->data);
        temp = temp->next;
    }
    return;
}

void free_list(node* head){
    node* temp;
    while(head!=NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
    return;
}