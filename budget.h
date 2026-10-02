#ifndef BUDGET_H
#define BUDGET_H

#include "common.h"

void enterDepartmentBudget(void);
void enterExpenditure(void);
void calculateBudget(void);
void displayBudgets(void);
void showOverBudgetDepts(void);

int getBudgetCount(void);
Budget* getBudgets(void);

#endif