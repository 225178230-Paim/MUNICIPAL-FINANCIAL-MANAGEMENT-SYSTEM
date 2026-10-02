#include <stdio.h>
#include "budget.h"
#include "common.h"

static Budget budgets[MAX_DEPARTMENTS];
static int budgetCount = 0;

void enterDepartmentBudget(void) { printf("[Budget module not yet implemented]\n"); }
void enterExpenditure(void)      { printf("[Budget module not yet implemented]\n"); }
void calculateBudget(void)       { printf("[Budget module not yet implemented]\n"); }
void displayBudgets(void)        { printf("[Budget module not yet implemented]\n"); }
void showOverBudgetDepts(void)   { printf("[Budget module not yet implemented]\n"); }

int getBudgetCount(void)   { return budgetCount; }
Budget* getBudgets(void)   { return budgets; }