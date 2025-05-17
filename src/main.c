#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "dll.h"
#include "expense.h"
#include "fileio.h"

void add_expense(node** head){
    char category[25],c;
    int i=0;
    float amount;

    printf("Enter the amount spend: ");
    scanf("%f",&amount);

    printf("Enter the category of spending(in one word): ");
    getchar();
    while((c=getchar())!='\n'){
        category[i]=c;
        i++;
    }
    category[i]='\0';

    expense e = create_expense(amount, category);
    insert_end(head, e);
    printf("Expense added.");
    return;
}

void view_expense(node* head){
    print_all_node(head);
    return;
}

void save_exit(node* head){
    save_expenses(head);
    printf("All expenses saved!\n");
}

int main(){
    node* head = NULL;

    if(load_expenses(&head)==0){
        printf("No saved expenses found. Starting fresh.\n");
    }
    int choice;
    do{
        printf("\n=== Expense Tracker ===\n");
        printf("1. Add Expense\n");
        printf("2. View All Expenses\n");
        printf("3. Analyze Total Spent\n");
        printf("4. Save & Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();

        switch(choice){

            case 1: add_expense(&head);
                    break;

            case 2: view_expense(head);
                    break;

            case 3: //future
                    break;

            case 4: save_exit(head);
                    break;

            default: printf("Invalid choice.");
                    break;
        }

    }while(choice!=4);

    free_list(head);
    return 0;
}