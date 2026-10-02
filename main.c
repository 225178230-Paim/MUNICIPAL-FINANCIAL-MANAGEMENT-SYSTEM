#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "common.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

int    getValidInt(const char *prompt, int min, int max);
double getValidDouble(const char *prompt, double min, double max);
void   getValidString(const char *prompt, char *buffer, int size);
int    getValidMenuChoice(int min, int max);
void   clearInputBuffer(void);

void displayMainMenu(void);
void displayEmployeeMenu(void);
void displayBudgetMenu(void);
void displaySupplierMenu(void);
void displayAssetMenu(void);
void displayReportsMenu(void);

void handleEmployeeMenu(void);
void handleBudgetMenu(void);
void handleSupplierMenu(void);
void handleAssetMenu(void);
void handleReportsMenu(void);

int main(void)
{
    int choice;

    printf("\n=====================================================\n");
    printf("   WELCOME TO THE MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("                    SYSTEM (MFMS)\n");
    printf("=====================================================\n");

    do {
        displayMainMenu();
        choice = getValidMenuChoice(1, 6);

        switch (choice) {
            case 1: handleEmployeeMenu(); break;
            case 2: handleBudgetMenu();   break;
            case 3: handleSupplierMenu(); break;
            case 4: handleAssetMenu();    break;
            case 5: handleReportsMenu();  break;
            case 6: printf("\nThanks for using MFMS. Goodbye!\n\n"); break;
            default: printf("\nHmm, that choice isn't on the menu. Try again.\n"); break;
        }
    } while (choice != 6);

    return 0;
}

void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int getValidInt(const char *prompt, int min, int max)
{
    int  value;
    char term;
    int  result;

    while (1) {
        printf("%s", prompt);
        result = scanf("%d%c", &value, &term);

        if (result != 2 || term != '\n') {
            printf("  ! That's not a whole number. Try again.\n");
            clearInputBuffer();
            continue;
        }

        if (value < min || value > max) {
            printf("  ! Please enter a number between %d and %d.\n", min, max);
            continue;
        }

        return value;
    }
}

double getValidDouble(const char *prompt, double min, double max)
{
    double value;
    char   term;
    int    result;

    while (1) {
        printf("%s", prompt);
        result = scanf("%lf%c", &value, &term);

        if (result != 2 || term != '\n') {
            printf("  ! That's not a valid number. Try again.\n");
            clearInputBuffer();
            continue;
        }

        if (value < min || value > max) {
            printf("  ! Please enter a number between %.2f and %.2f.\n", min, max);
            continue;
        }

        return value;
    }
}

void getValidString(const char *prompt, char *buffer, int size)
{
    int onlySpaces;
    int i;

    while (1) {
        printf("%s", prompt);

        if (fgets(buffer, size, stdin) == NULL) {
            clearInputBuffer();
            continue;
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        onlySpaces = 1;
        for (i = 0; buffer[i] != '\0'; i++) {
            if (!isspace((unsigned char)buffer[i])) {
                onlySpaces = 0;
                break;
            }
        }

        if (onlySpaces) {
            printf("  ! That can't be empty. Please type something.\n");
            continue;
        }

        return;
    }
}

int getValidMenuChoice(int min, int max)
{
    return getValidInt("Enter your choice: ", min, max);
}

void displayMainMenu(void)
{
    printf("\n=====================================================\n");
    printf("        MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("=====================================================\n");
    printf("  1. Employee Management\n");
    printf("  2. Budget Management\n");
    printf("  3. Supplier Management\n");
    printf("  4. Asset Management\n");
    printf("  5. Reports\n");
    printf("  6. Exit\n");
    printf("-----------------------------------------------------\n");
}

void displayEmployeeMenu(void)
{
    printf("\n----------- EMPLOYEE MANAGEMENT -----------\n");
    printf("  1. Add Employee\n");
    printf("  2. Display All Employees\n");
    printf("  3. Search Employee by ID\n");
    printf("  4. Calculate Employee Salary\n");
    printf("  5. Display Employee Details\n");
    printf("  6. Back to Main Menu\n");
    printf("-------------------------------------------\n");
}

void displayBudgetMenu(void)
{
    printf("\n------------ BUDGET MANAGEMENT ------------\n");
    printf("  1. Enter Departmental Budget\n");
    printf("  2. Enter Expenditure\n");
    printf("  3. Calculate Remaining Budget\n");
    printf("  4. Display All Budgets\n");
    printf("  5. Departments Over Budget\n");
    printf("  6. Back to Main Menu\n");
    printf("-------------------------------------------\n");
}

void displaySupplierMenu(void)
{
    printf("\n----------- SUPPLIER MANAGEMENT -----------\n");
    printf("  1. Add Supplier\n");
    printf("  2. Display All Suppliers\n");
    printf("  3. Search Supplier by ID\n");
    printf("  4. Search Supplier by Name\n");
    printf("  5. Back to Main Menu\n");
    printf("-------------------------------------------\n");
}

void displayAssetMenu(void)
{
    printf("\n------------- ASSET MANAGEMENT ------------\n");
    printf("  1. Add Asset\n");
    printf("  2. Display All Assets\n");
    printf("  3. Search Asset by ID\n");
    printf("  4. Search Asset by Type\n");
    printf("  5. Back to Main Menu\n");
    printf("-------------------------------------------\n");
}

void displayReportsMenu(void)
{
    printf("\n------------------ REPORTS ----------------\n");
    printf("  1. Employee Report\n");
    printf("  2. Budget Report\n");
    printf("  3. Supplier Report\n");
    printf("  4. Asset Report\n");
    printf("  5. Back to Main Menu\n");
    printf("-------------------------------------------\n");
}

void handleEmployeeMenu(void)
{
    int choice;
    do {
        displayEmployeeMenu();
        choice = getValidMenuChoice(1, 6);

        switch (choice) {
            case 1: addEmployee();         break;
            case 2: displayEmployees();    break;
            case 3: searchEmployee();      break;
            case 4: calculateSalaryInfo(); break;
            case 5: displayEmployeeInfo(); break;
            case 6:                        break;
            default: printf("Invalid choice.\n"); break;
        }
    } while (choice != 6);
}

void handleBudgetMenu(void)
{
    int choice;
    do {
        displayBudgetMenu();
        choice = getValidMenuChoice(1, 6);

        switch (choice) {
            case 1: enterDepartmentBudget(); break;
            case 2: enterExpenditure();      break;
            case 3: calculateBudget();       break;
            case 4: displayBudgets();        break;
            case 5: showOverBudgetDepts();   break;
            case 6:                          break;
            default: printf("Invalid choice.\n"); break;
        }
    } while (choice != 6);
}

void handleSupplierMenu(void)
{
    int choice;
    do {
        displaySupplierMenu();
        choice = getValidMenuChoice(1, 5);

        switch (choice) {
            case 1: addSupplier();          break;
            case 2: displaySuppliers();     break;
            case 3: searchSupplierByID();   break;
            case 4: searchSupplierByName(); break;
            case 5:                         break;
            default: printf("Invalid choice.\n"); break;
        }
    } while (choice != 5);
}

void handleAssetMenu(void)
{
    int choice;
    do {
        displayAssetMenu();
        choice = getValidMenuChoice(1, 5);

        switch (choice) {
            case 1: addAsset();          break;
            case 2: displayAssets();     break;
            case 3: searchAssetByID();   break;
            case 4: searchAssetByType(); break;
            case 5:                      break;
            default: printf("Invalid choice.\n"); break;
        }
    } while (choice != 5);
}

void handleReportsMenu(void)
{
    int choice;
    do {
        displayReportsMenu();
        choice = getValidMenuChoice(1, 5);

        switch (choice) {
            case 1: employeeReport(); break;
            case 2: budgetReport();   break;
            case 3: supplierReport(); break;
            case 4: assetReport();    break;
            case 5:                   break;
            default: printf("Invalid choice.\n"); break;
        }
    } while (choice != 5);
}
