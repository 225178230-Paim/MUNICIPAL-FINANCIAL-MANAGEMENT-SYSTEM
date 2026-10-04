
#include <stdio.h>
#include <string.h>
#include "employees.h"

static Employee employees[MAX_EMPLOYEES];
static int employeeCount = 0;

float calculateSalary(float basic, float housing, float transport) {
    return basic + housing + transport;
}

float calculateNetSalary(float gross, float tax) {
    return gross - tax;
}

void addEmployee(void) {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("\nError: Maximum employee capacity reached.\n");
        return;
    }

    Employee e;
    printf("\n--- Add New Employee ---\n");
    printf("Enter Employee ID: ");
    scanf("%d", &e.id);
    getchar();

    printf("Enter Employee Name: ");
    fgets(e.name, sizeof(e.name), stdin);
    e.name[strcspn(e.name, "\n")] = '\0';

    printf("Enter Basic Salary: ");
    scanf("%f", &e.basicSalary);

    printf("Enter Housing Allowance: ");
    scanf("%f", &e.housingAllowance);

    printf("Enter Transport Allowance: ");
    scanf("%f", &e.transportAllowance);

    printf("Enter Tax: ");
    scanf("%f", &e.tax);

    e.grossSalary = calculateSalary(e.basicSalary, e.housingAllowance, e.transportAllowance);
    e.netSalary = calculateNetSalary(e.grossSalary, e.tax);

    employees[employeeCount] = e;
    employeeCount++;

    printf("\nEmployee added successfully!\n");
    printf("Gross Salary: %.2f\n", e.grossSalary);
    printf("Net Salary: %.2f\n", e.netSalary);

    if (e.netSalary >= 20000.0f) {
        printf("Income Category: High Income\n");
    } else {
        printf("Income Category: Standard Income\n");
    }
}

void listEmployees(void) {
    if (employeeCount == 0) {
        printf("\nNo employee records available.\n");
        return;
    }

    printf("\n======================= EMPLOYEE LIST =======================\n");
    printf("%-5s %-20s %-10s %-10s %-10s\n", "ID", "Name", "Gross", "Tax", "Net");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("%-5d %-20s %-10.2f %-10.2f %-10.2f\n",
               employees[i].id, employees[i].name,
               employees[i].grossSalary, employees[i].tax, employees[i].netSalary);
    }
    printf("=============================================================\n");
}

int searchEmployee(int id) {
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            return i;
        }
    }
    return -1;
}

void displaySalaryReport(void) {
    if (employeeCount == 0) {
        printf("\nNo employee records available for analysis.\n");
        return;
    }

    float total = 0.0f;
    float highest = employees[0].netSalary;
    float lowest = employees[0].netSalary;

    for (int i = 0; i < employeeCount; i++) {
        float net = employees[i].netSalary;
        total += net;
        if (net > highest) highest = net;
        if (net < lowest) lowest = net;
    }

    float average = total / employeeCount;

    printf("\n--- MUNICIPAL SALARY ANALYSIS REPORT ---\n");
    printf("Total Employees : %d\n", employeeCount);
    printf("Total Expenditure: %.2f\n", total);
    printf("Average Salary   : %.2f\n", average);
    printf("Highest Salary   : %.2f\n", highest);
    printf("Lowest Salary    : %.2f\n", lowest);
    printf("----------------------------------------\n");
}

void sortEmployeesBySalary(void) {
    if (employeeCount < 2) {
        printf("\nNot enough records to sort.\n");
        return;
    }

    Employee temp;
    for (int i = 0; i < employeeCount - 1; i++) {
        for (int j = 0; j < employeeCount - i - 1; j++) {
            if (employees[j].netSalary > employees[j + 1].netSalary) {
                temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
    printf("\nEmployees sorted by net salary (Ascending order).\n");
    listEmployees();
}

void saveEmployeesToFile(void) {
    FILE *fp = fopen("employees.txt", "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return;
    }

    for (int i = 0; i < employeeCount; i++) {
        fprintf(fp, "%d|%s|%.2f|%.2f|%.2f|%.2f|%.2f|%.2f\n",
                employees[i].id, employees[i].name, employees[i].basicSalary,
                employees[i].housingAllowance, employees[i].transportAllowance,
                employees[i].tax, employees[i].grossSalary, employees[i].netSalary);
    }

    fclose(fp);
    printf("\nData successfully saved to employees.txt (%d records).\n", employeeCount);
}

void loadEmployeesFromFile(void) {
    FILE *fp = fopen("employees.txt", "r");
    if (fp == NULL) {
        perror("Error opening employees.txt");
        return;
    }

    employeeCount = 0;
    while (fscanf(fp, "%d|%49[^|]|%f|%f|%f|%f|%f|%f\n",
                  &employees[employeeCount].id,
                  employees[employeeCount].name,
                  &employees[employeeCount].basicSalary,
                  &employees[employeeCount].housingAllowance,
                  &employees[employeeCount].transportAllowance,
                  &employees[employeeCount].tax,
                  &employees[employeeCount].grossSalary,
                  &employees[employeeCount].netSalary) == 8) {
        employeeCount++;
        if (employeeCount >= MAX_EMPLOYEES) break;
    }

    fclose(fp);
    printf("\nData successfully loaded from employees.txt (%d records).\n", employeeCount);
}