#ifndef EXPENSE_H
#define EXPENSE_H

typedef struct expense{
    float amount;       //eg: 250
    char category[25];  //eg: "food", "clothes", etc
}expense;

expense create_expense(float amt, char* cat);
void print_expense(expense e);

#endif