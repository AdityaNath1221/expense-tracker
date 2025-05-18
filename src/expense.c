#include <stdio.h>
#include <string.h>
#include "expense.h"

expense create_expense(float amt, char* cat){
    expense e;

    e.amount = amt;

    strcpy(e.category, cat);

    return e;
}

void print_expense(expense e){
    printf("Amount - %.2f, Category - %s \n", e.amount, e.category);
}