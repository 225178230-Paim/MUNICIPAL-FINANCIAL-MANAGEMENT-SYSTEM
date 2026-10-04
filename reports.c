#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "common.h"

void employeeReport(void)
{
    int      count = getEmployeeCount();
    Employee *emps  = getEmployees();
    double   total = 0.0, max = 0.0, min = 0.0;
    int      i;

    printf("\n===== EMPLOYEE REPORT =====\n");

    if (count == 0) {
        printf("Total Employees: 0\n");
        printf("Average Salary: N$0.00\n");
        printf("No employee data available.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        double s = calculateTotalSalary(emps[i]);
        total += s;
        if (i == 0 || s > max) max = s;
        if (i == 0 || s < min) min = s;
    }

    printf("Total Employees: %d\n", count);
    printf("Average Salary: N$%.2f\n", total / count);
    printf("Highest Salary: N$%.2f\n", max);
    printf("Lowest Salary: N$%.2f\n", min);
}

void budgetReport(void)
{
    int    count = getBudgetCount();
    Budget *budgets = getBudgets();
    double totalAllocated = 0.0;
    double totalExpenditure = 0.0;
    int    i;
    int    overCount = 0;

    printf("\n===== BUDGET REPORT =====\n");

    if (count == 0) {
        printf("No budgets recorded yet.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        totalAllocated   += budgets[i].allocatedBudget;
        totalExpenditure += budgets[i].expenditure;
    }

    printf("Total Allocated Budget: N$%.2f\n", totalAllocated);
    printf("Total Expenditure:      N$%.2f\n", totalExpenditure);
    printf("Remaining Budget:       N$%.2f\n", totalAllocated - totalExpenditure);

    printf("\nDepartments exceeding budget:\n");
    for (i = 0; i < count; i++) {
        double remaining = budgets[i].allocatedBudget - budgets[i].expenditure;
        if (remaining < 0) {
            printf("  - %s (over by N$%.2f)\n", budgets[i].department, -remaining);
            overCount++;
        }
    }
    if (overCount == 0) {
        printf("  None - all departments are within budget.\n");
    }
}

void supplierReport(void)
{
    int       count = getSupplierCount();
    Supplier *suppliers = getSuppliers();
    int       i;

    printf("\n===== SUPPLIER REPORT =====\n");

    if (count == 0) {
        printf("No suppliers registered yet.\n");
        return;
    }

    printf("%-10s %-20s %-25s %-15s %-15s\n",
           "ID", "Name", "Email", "Telephone", "Town");
    printf("--------------------------------------------------------------------------------\n");

    for (i = 0; i < count; i++) {
        printf("%-10s %-20s %-25s %-15s %-15s\n",
               suppliers[i].id,
               suppliers[i].name,
               suppliers[i].email,
               suppliers[i].telephone,
               suppliers[i].town);
    }

    printf("\nTotal Suppliers: %d\n", count);
}

void assetReport(void)
{
    int    count = getAssetCount();
    Asset *assets = getAssets();
    int    i;

    printf("\n===== ASSET REPORT =====\n");

    if (count == 0) {
        printf("No assets registered yet.\n");
        return;
    }

    printf("%-10s %-20s %-15s %-12s %-15s %-10s\n",
           "ID", "Name", "Type", "Value (N$)", "Department", "Condition");
    printf("------------------------------------------------------------------------------------\n");

    for (i = 0; i < count; i++) {
        printf("%-10s %-20s %-15s %-12.2f %-15s %-10s\n",
               assets[i].id,
               assets[i].name,
               assets[i].type,
               assets[i].purchaseValue,
               assets[i].department,
               assets[i].condition);
    }

    printf("\nTotal Assets: %d\n", count);
}