#include <stdio.h>
#include <string.h>
#include "budget.h"
#include "common.h"

static Budget budgets[MAX_DEPARTMENTS];
static int budgetCount = 0;

static int findDepartment(const char *name)
{
    int i;
    for (i = 0; i < budgetCount; i++) {
        if (strcmp(budgets[i].department, name) == 0) {
            return i;
        }
    }
    return -1;
}

void enterDepartmentBudget(void)
{
    char name[DEPT_LEN];
    int  i;
    double amount;

    getValidString("\nEnter department name: ", name, DEPT_LEN);

    i = findDepartment(name);

    if (i == -1) {
        if (budgetCount >= MAX_DEPARTMENTS) {
            printf("Error: maximum department limit reached.\n");
            return;
        }
        i = budgetCount;
        strncpy(budgets[i].department, name, DEPT_LEN - 1);
        budgets[i].department[DEPT_LEN - 1] = '\0';
        budgets[i].allocatedBudget = 0;
        budgets[i].expenditure = 0;
        budgetCount++;
    }

    amount = getValidDouble("Enter allocated budget (N$): ", 0, 1000000000);
    budgets[i].allocatedBudget = amount;

    printf("Budget for '%s' recorded successfully.\n", budgets[i].department);
}

void enterExpenditure(void)
{
    char name[DEPT_LEN];
    int  i;
    double spent;

    getValidString("\nEnter department name: ", name, DEPT_LEN);

    i = findDepartment(name);
    if (i == -1) {
        printf("Department '%s' does not exist. Add its budget first.\n", name);
        return;
    }

    spent = getValidDouble("Enter expenditure (N$): ", 0, 1000000000);
    budgets[i].expenditure = spent;

    printf("Expenditure for '%s' recorded successfully.\n", budgets[i].department);
}

void calculateBudget(void)
{
    char name[DEPT_LEN];
    int  i;
    double remaining;

    if (budgetCount == 0) {
        printf("\nNo budgets recorded yet.\n");
        return;
    }

    getValidString("\nEnter department name: ", name, DEPT_LEN);

    i = findDepartment(name);
    if (i == -1) {
        printf("Department '%s' does not exist.\n", name);
        return;
    }

    remaining = budgets[i].allocatedBudget - budgets[i].expenditure;

    printf("\nDepartment:      %s\n", budgets[i].department);
    printf("Allocated Budget: N$%.2f\n", budgets[i].allocatedBudget);
    printf("Expenditure:      N$%.2f\n", budgets[i].expenditure);
    printf("Remaining Budget: N$%.2f\n", remaining);
    printf("Status: %s\n", remaining >= 0 ? "WITHIN BUDGET" : "EXCEEDED BUDGET");
}

void displayBudgets(void)
{
    int i;

    if (budgetCount == 0) {
        printf("\nNo departments have been recorded yet.\n");
        return;
    }

    printf("\n========== ALL BUDGETS ==========\n");

    for (i = 0; i < budgetCount; i++) {
        double remaining = budgets[i].allocatedBudget - budgets[i].expenditure;

        printf("\nDepartment:       %s\n", budgets[i].department);
        printf("Allocated Budget: N$%.2f\n", budgets[i].allocatedBudget);
        printf("Expenditure:      N$%.2f\n", budgets[i].expenditure);
        printf("Remaining Budget: N$%.2f\n", remaining);
        printf("Status:           %s\n",
               remaining >= 0 ? "WITHIN BUDGET" : "EXCEEDED BUDGET");
        printf("---------------------------------\n");
    }
}

void showOverBudgetDepts(void)
{
    int i;
    int count = 0;

    printf("\n----- DEPARTMENTS OVER BUDGET -----\n");

    for (i = 0; i < budgetCount; i++) {
        double remaining = budgets[i].allocatedBudget - budgets[i].expenditure;
        if (remaining < 0) {
            printf("- %s (Exceeded by: N$%.2f)\n", budgets[i].department, -remaining);
            count++;
        }
    }

    if (count == 0) {
        printf("No departments have exceeded their budget.\n");
    }
}

int getBudgetCount(void)
{
    return budgetCount;
}

Budget* getBudgets(void)
{
    return budgets;
}