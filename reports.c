#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "common.h"

void employeeReport(void) {
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

void budgetReport(void)   { printf("[Budget report not yet implemented]\n"); }
void supplierReport(void) { printf("[Supplier report not yet implemented]\n"); }
void assetReport(void)    { printf("[Asset report not yet implemented]\n"); }