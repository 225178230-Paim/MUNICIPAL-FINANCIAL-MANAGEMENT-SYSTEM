#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "common.h"

static Employee employees[MAX_EMPLOYEES];
static int employeeCount = 0;

double calculateTotalSalary(Employee e)
{
    return e.basicSalary + e.housingAllowance + e.transportAllowance;
}

double calculateNetSalary(Employee e)
{
    return calculateTotalSalary(e) - e.tax;
}

void addEmployee(void)
{
    Employee e;

    if (employeeCount >= MAX_EMPLOYEES) {
        printf("\nError: maximum employee capacity reached.\n");
        return;
    }

    printf("\n--- Add New Employee ---\n");

    getValidString("Enter Employee ID: ", e.id, ID_LEN);
    getValidString("Enter Name: ", e.name, NAME_LEN);
    getValidString("Enter Department: ", e.department, DEPT_LEN);

    e.basicSalary        = getValidDouble("Enter Basic Salary (N$): ", 0, 1000000000);
    e.housingAllowance   = getValidDouble("Enter Housing Allowance (N$): ", 0, 1000000000);
    e.transportAllowance = getValidDouble("Enter Transport Allowance (N$): ", 0, 1000000000);
    e.tax                = getValidDouble("Enter Tax (N$): ", 0, 1000000000);

    employees[employeeCount] = e;
    employeeCount++;

    printf("\nEmployee added successfully!\n");
    printf("Gross Salary: N$%.2f\n", calculateTotalSalary(e));
    printf("Net Salary:   N$%.2f\n", calculateNetSalary(e));

    if (calculateNetSalary(e) >= 20000.0) {
        printf("Income Category: High Income\n");
    } else {
        printf("Income Category: Standard Income\n");
    }
}

void displayEmployees(void)
{
    int i;

    if (employeeCount == 0) {
        printf("\nNo employee records available.\n");
        return;
    }

    printf("\n================== EMPLOYEE LIST ==================\n");
    printf("%-10s %-20s %-15s %-12s\n", "ID", "Name", "Department", "Net Salary");
    printf("---------------------------------------------------\n");

    for (i = 0; i < employeeCount; i++) {
        printf("%-10s %-20s %-15s N$%-11.2f\n",
               employees[i].id,
               employees[i].name,
               employees[i].department,
               calculateNetSalary(employees[i]));
    }

    printf("===================================================\n");
}

void searchEmployee(void)
{
    char id[ID_LEN];
    int  i;

    if (employeeCount == 0) {
        printf("\nNo employees to search.\n");
        return;
    }

    getValidString("\nEnter Employee ID to search: ", id, ID_LEN);

    for (i = 0; i < employeeCount; i++) {
        if (strcmp(employees[i].id, id) == 0) {
            printf("\nEmployee found:\n");
            printf("  ID:         %s\n", employees[i].id);
            printf("  Name:       %s\n", employees[i].name);
            printf("  Department: %s\n", employees[i].department);
            return;
        }
    }

    printf("\nNo employee found with ID '%s'.\n", id);
}

void calculateSalaryInfo(void)
{
    char id[ID_LEN];
    int  i;
    double gross, net;

    if (employeeCount == 0) {
        printf("\nNo employees to calculate.\n");
        return;
    }

    getValidString("\nEnter Employee ID: ", id, ID_LEN);

    for (i = 0; i < employeeCount; i++) {
        if (strcmp(employees[i].id, id) == 0) {
            gross = calculateTotalSalary(employees[i]);
            net   = calculateNetSalary(employees[i]);

            printf("\n--- SALARY BREAKDOWN ---\n");
            printf("Employee:            %s (%s)\n", employees[i].name, employees[i].id);
            printf("Basic Salary:        N$%.2f\n", employees[i].basicSalary);
            printf("Housing Allowance:   N$%.2f\n", employees[i].housingAllowance);
            printf("Transport Allowance: N$%.2f\n", employees[i].transportAllowance);
            printf("Gross Salary:        N$%.2f\n", gross);
            printf("Tax:                 N$%.2f\n", employees[i].tax);
            printf("Net Salary:          N$%.2f\n", net);
            return;
        }
    }

    printf("\nNo employee found with ID '%s'.\n", id);
}

void displayEmployeeInfo(void)
{
    char id[ID_LEN];
    int  i;

    if (employeeCount == 0) {
        printf("\nNo employee records available.\n");
        return;
    }

    getValidString("\nEnter Employee ID: ", id, ID_LEN);

    for (i = 0; i < employeeCount; i++) {
        if (strcmp(employees[i].id, id) == 0) {
            printf("\n--- EMPLOYEE DETAILS ---\n");
            printf("ID:                   %s\n", employees[i].id);
            printf("Name:                 %s\n", employees[i].name);
            printf("Department:           %s\n", employees[i].department);
            printf("Basic Salary:         N$%.2f\n", employees[i].basicSalary);
            printf("Housing Allowance:    N$%.2f\n", employees[i].housingAllowance);
            printf("Transport Allowance:  N$%.2f\n", employees[i].transportAllowance);
            printf("Gross Salary:         N$%.2f\n", calculateTotalSalary(employees[i]));
            printf("Tax:                  N$%.2f\n", employees[i].tax);
            printf("Net Salary:           N$%.2f\n", calculateNetSalary(employees[i]));
            return;
        }
    }

    printf("\nNo employee found with ID '%s'.\n", id);
}

void sortEmployeesBySalary(void)
{
    int i, j;
    Employee temp;

    if (employeeCount < 2) {
        printf("\nNot enough records to sort.\n");
        return;
    }

    for (i = 0; i < employeeCount - 1; i++) {
        for (j = 0; j < employeeCount - i - 1; j++) {
            if (calculateNetSalary(employees[j]) > calculateNetSalary(employees[j + 1])) {
                temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }

    printf("\nEmployees sorted by net salary (ascending).\n");
    displayEmployees();
}

void saveEmployeesToFile(void)
{
    FILE *fp;
    int   i;

    fp = fopen("employees.txt", "w");
    if (fp == NULL) {
        printf("\nError opening file for writing.\n");
        return;
    }

    for (i = 0; i < employeeCount; i++) {
        fprintf(fp, "%s|%s|%s|%.2f|%.2f|%.2f|%.2f\n",
                employees[i].id,
                employees[i].name,
                employees[i].department,
                employees[i].basicSalary,
                employees[i].housingAllowance,
                employees[i].transportAllowance,
                employees[i].tax);
    }

    fclose(fp);
    printf("\nSaved %d employee(s) to employees.txt.\n", employeeCount);
}

void loadEmployeesFromFile(void)
{
    FILE *fp;
    char  line[256];

    fp = fopen("employees.txt", "r");
    if (fp == NULL) {
        printf("\nNo employees.txt file found.\n");
        return;
    }

    employeeCount = 0;

    while (employeeCount < MAX_EMPLOYEES &&
           fgets(line, sizeof(line), fp) != NULL) {

        Employee *e = &employees[employeeCount];

        if (sscanf(line, "%9[^|]|%49[^|]|%29[^|]|%lf|%lf|%lf|%lf",
                   e->id,
                   e->name,
                   e->department,
                   &e->basicSalary,
                   &e->housingAllowance,
                   &e->transportAllowance,
                   &e->tax) == 7) {
            employeeCount++;
        }
    }

    fclose(fp);
    printf("\nLoaded %d employee(s) from employees.txt.\n", employeeCount);
}

int getEmployeeCount(void)
{
    return employeeCount;
}

Employee* getEmployees(void)
{
    return employees;
}