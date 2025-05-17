#include <stdio.h>
#include <strings.h>
#include "expense.h"

expense create_expense(float amt, char* cat){
    expense e;

    e.amount = amt;

    e.category = strcpy(e.category, cat);
    e.category[sizeof(cat)-1] = '\0';

    return e;
}

void print_expense(expense e){
    printf("Amount - %.2f, Category - %s", e.amount, e.category);
}