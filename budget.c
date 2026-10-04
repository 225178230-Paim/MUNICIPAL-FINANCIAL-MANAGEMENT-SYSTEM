#include "budget.h"
#include <stdio.h>
#include <string.h>

#define MAX_DEPARTMENTS 30
#define MAX_NAME_LEN 60

typedef struct {
    char name[MAX_NAME_LEN];
    double allocatedBudget;
    double expenditure;
    int hasBudget;
    int hasExpenditure;
} DepartmentBudget;

DepartmentBudget municipalBudgets[MAX_DEPARTMENTS];
int totalDepartments = 0;

int findDepartment (const char* name) {
    for (int i = 0; i < totalDepartments; i++) {
        if (strcasecmp(municipalBudgets[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}
void enterBudget() {
    char name[MAX_NAME_LEN];
    double budget;

    printf("\n Enter Department Name:");
    scanf(" %[^\n]s", name);

    int i = findDepartment(name);

    if (i = -1) {
        if (totalDepartments >= MAX_DEPARTMENTS) {
            printf("Error: Maximum department limit reached.\n");
            return;
        }
        i = totalDepartments;
        strcpy(municipalBudgets[i].name, name);
        municipalBudgets[i].expenditure = 0;
        municipalBudgets[i].hasExpenditure = 0;
        totalDepartments++;
    }
    printf("Enter Allocated Budget (N$):");
    scanf("%lf", &budget);

    municipalBudgets[i].allocatedBudget = budget;
    printf("Budget for '%s' is recorded successfully.\n", name);
}
void enterExpenditure() {
    char name[MAX_NAME_LEN];
    double spent;

    printf("\nEnter Deparment Name: ");
    scanf(" %[^\n]s", name);

    int i = findDepartment(name);

    if (i == -1) {
        printf("Deparment '%s' does not exist yet, First lets create its budget using option 1.\n, name ");
        return;
    }

    printf("Enter The Current Expenditure (N$):");
    scanf("%lf", &spent);

    municipalBudgets[i].expenditure = spent;
    municipalBudgets[i].hasExpenditure = 1;
    printf("Expenditure for '%s' is recorded successfully.\n", municipalBudgets[i].name);

}
void displayBudgetInformation() {
    if (totalDepartments == 0) {
        printf("No departments have been recorded yet.\n");
        return ;
    }

    for (int i = 0; i < totalDepartments; i++) {
        
        double remainingBudget = municipalBudgets[i].allocatedBudget - municipalBudgets[i].expenditure;
        printf("\nDepartment: %s\n", municipalBudgets[i].name);
        printf("\nAllocated Budget: N$%.0f\n", municipalBudgets[i].allocatedBudget);
        printf("Expenditure: N$%.0f\n", municipalBudgets[i].expenditure);
        printf("Remaning Budget: N$%.0f\n", remainingBudget);
        printf("----------------------------------------------------\n");    

        if (remainingBudget >= 0) {
            printf("Status: WITHIN BUDGET\n");
        } else {
            printf("Status: EXCEEDED BUDGET\n");
        }
        printf("--------------------------------\n");
    }
    printf("\n");
}
void calculateRemainingBudget() {
    char name[MAX_NAME_LEN];
    printf("\n Enter Department name:");
    scanf(" %[^\n]s", name);
    int i = findDepartment(name);
    if (i == -1) {
        printf("Department '%s' does not exist.\n", name);
        return;
}
    double remainingBudget = municipalBudgets[i].allocatedBudget - municipalBudgets[i].expenditure;
    printf("Remaining Budget: N$%.2f\n", remainingBudget);
}
void displayExpenditureWithinBudget() {
    char name[MAX_NAME_LEN];
    printf("\nEnter Department Name:");
    scanf(" %[^\n]s", name);
    int i = findDepartment(name);
    if (i == -1) {
        printf("Department '%s' does not exist.\n", name);
        return;
    }
    if (municipalBudgets[i].expenditure <= municipalBudgets[i].allocatedBudget)
        printf("Status: WITHIN BUDGET\n");
    else
        printf("Status: EXCEEDED BUDGET\n");
}
void identifyDepartmentExceeded() {
    int count = 0;
    printf("\n--- DEPARTMENT EXCEEDED BUDGET ----\n");

    for (int i =0; i < totalDepartments; i++) {
        double remainingBudget = municipalBudgets[i].allocatedBudget  - municipalBudgets[i].expenditure;
        if (remainingBudget < 0) {
            printf("- %s (Exceeded by: N$%.2f\n", municipalBudgets[i].name, -remainingBudget);
            count++;
        }
    }
    if (count == 0) {
        printf("All departments are safely within the allocated budgets.\n");
    }
}
void processBudget() {
    char name[MAX_NAME_LEN];
    double budget, spent;

    printf("\nEnter Department Name:");
    scanf(" %59[^\n]",municipalBudgets[totalDepartments].name);

    int i = findDepartment(name);
    if (i == -1) {
        if (totalDepartments >= MAX_NAME_LEN) {
        printf("Maximum department limit reached.\n");
        return;
    }
    i = totalDepartments;
    strcpy(municipalBudgets[i].name, name);
    totalDepartments++;
}
printf("Enter allocate budget (N$):");
scanf("%lf", &budget);
printf("Enter expenditure (N$):");
scanf("%lf", &spent);

municipalBudgets[i].allocatedBudget = budget;
municipalBudgets[i].expenditure = spent;
municipalBudgets[i].hasBudget = 1;
municipalBudgets[i].hasExpenditure =1;

double remaining = budget- spent;
printf("\nRemaining Budget: N$%.2f\n", remaining);

if (remaining >= 0)
    printf("Status: WITHIN BUDGET\n");
else
    printf("Status: EXCEEDED BUDGET\n");
displayBudgetInformation();
identifyDepartmentExceeded();
}
    
