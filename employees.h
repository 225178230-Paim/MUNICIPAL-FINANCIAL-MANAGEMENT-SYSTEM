#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include "common.h"

void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
void calculateSalaryInfo(void);
void displayEmployeeInfo(void);

double calculateTotalSalary(Employee e);

int getEmployeeCount(void);
Employee* getEmployees(void);

#endif