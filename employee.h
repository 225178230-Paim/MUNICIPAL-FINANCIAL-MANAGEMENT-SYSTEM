
#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 50

typedef struct {
    int id;
    char name[50];
    float basicSalary;
    float housingAllowance;
    float transportAllowance;
    float tax;
    float grossSalary;
    float netSalary;
} Employee;

float calculateSalary(float basic, float housing, float transport);
float calculateNetSalary(float gross, float tax);
void addEmployee(void);
void listEmployees(void);
int searchEmployee(int id);
void displaySalaryReport(void);
void sortEmployeesBySalary(void);
void saveEmployeesToFile(void);
void loadEmployeesFromFile(void);

#endif 