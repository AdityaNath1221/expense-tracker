#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "fileio.h"
#include "dll.h"
#include "expense.h"

int save_expenses(node* head){
    FILE* fh;
    fh = fopen("expenses.txt", "w");

    if(fh==NULL){
        printf("Error while opening file.");
        return 0;        
    }

    node* temp = head;
    while( temp != NULL ){
        fprintf(fh, "%0.2f, %s\n", temp->data.amount, temp->data.category);
        temp=temp->next;
    }

    fclose(fh);
    return 1;
}

int load_expenses(node** head){
    FILE* fh;
    fh = fopen("expenses.txt", "r");

    if(fh == NULL){
        printf("Error while opening file.");
        return 0;
    }

    char category[25];
    float amount;

    while(fscanf(fh, "%f,%s", &amount, category)==2){
        expense e = create_expense(amount, category);
        insert_end(head, e);
    }

    fclose(fh);
    return 0;
}