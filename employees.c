#include <stdio.h>
#include "employees.h"
#include "common.h"

static Employee employees[MAX_EMPLOYEES];
static int employeeCount = 0;

double calculateTotalSalary(Employee e) {
    return e.basicSalary + e.housingAllowance + e.transportAllowance;
}

void addEmployee(void)         { printf("[Employee module not yet implemented]\n"); }
void displayEmployees(void)    { printf("[Employee module not yet implemented]\n"); }
void searchEmployee(void)      { printf("[Employee module not yet implemented]\n"); }
void calculateSalaryInfo(void) { printf("[Employee module not yet implemented]\n"); }
void displayEmployeeInfo(void) { printf("[Employee module not yet implemented]\n"); }

int getEmployeeCount(void)   { return employeeCount; }
Employee* getEmployees(void) { return employees; }