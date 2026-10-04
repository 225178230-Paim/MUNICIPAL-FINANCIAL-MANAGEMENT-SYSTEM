#include <stdio.h>
#include <string.h>
#include "suppliers.h"
#include "common.h"

static Supplier suppliers[MAX_SUPPLIERS];
static int supplierCount = 0;

static int findSupplierByID(const char *id)
{
    int i;
    for (i = 0; i < supplierCount; i++) {
        if (strcmp(suppliers[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
}

static void printSupplier(const Supplier *s)
{
    printf("========================================\n");
    printf("              SUPPLIER FOUND\n");
    printf("========================================\n");
    printf("ID        : %s\n", s->id);
    printf("Name      : %s\n", s->name);
    printf("Email     : %s\n", s->email);
    printf("Telephone : %s\n", s->telephone);
    printf("Town      : %s\n", s->town);
    printf("========================================\n");
}

void addSupplier(void)
{
    Supplier newSupplier;
    char idBuffer[ID_LEN];

    if (supplierCount >= MAX_SUPPLIERS) {
        printf("\nSupplier storage is full (max %d).\n", MAX_SUPPLIERS);
        return;
    }

    printf("\n========================================\n");
    printf("             ADD NEW SUPPLIER\n");
    printf("========================================\n");

    while (1) {
        getValidString("Enter Supplier ID: ", idBuffer, ID_LEN);

        if (findSupplierByID(idBuffer) != -1) {
            printf("  ! Supplier ID already exists. Try a different one.\n");
            continue;
        }

        strncpy(newSupplier.id, idBuffer, ID_LEN - 1);
        newSupplier.id[ID_LEN - 1] = '\0';
        break;
    }

    getValidString("Enter Supplier Name: ", newSupplier.name, NAME_LEN);

    while (1) {
        getValidString("Enter Email: ", newSupplier.email, EMAIL_LEN);

        if (strchr(newSupplier.email, '@') == NULL) {
            printf("  ! Invalid email. Must contain '@'.\n");
            continue;
        }
        break;
    }

    getValidString("Enter Telephone Number: ", newSupplier.telephone, PHONE_LEN);
    getValidString("Enter Town/Location: ", newSupplier.town, TOWN_LEN);

    suppliers[supplierCount] = newSupplier;
    supplierCount++;

    printf("\n----------------------------------------\n");
    printf("Supplier added successfully!\n");
    printf("Supplier ID: %s\n", newSupplier.id);
    printf("Supplier Name: %s\n", newSupplier.name);
    printf("----------------------------------------\n");
}

void displaySuppliers(void)
{
    int i;

    if (supplierCount == 0) {
        printf("\nNo suppliers have been registered yet.\n");
        return;
    }

    printf("\n===============================================================\n");
    printf("                    REGISTERED SUPPLIERS\n");
    printf("===============================================================\n");

    printf("%-10s %-20s %-25s %-15s %-15s\n",
           "ID", "NAME", "EMAIL", "TELEPHONE", "TOWN");
    printf("-------------------------------------------------------------------------------\n");

    for (i = 0; i < supplierCount; i++) {
        printf("%-10s %-20s %-25s %-15s %-15s\n",
               suppliers[i].id,
               suppliers[i].name,
               suppliers[i].email,
               suppliers[i].telephone,
               suppliers[i].town);
    }

    printf("===============================================================\n");
    printf("Total Suppliers: %d\n", supplierCount);
}

void searchSupplierByID(void)
{
    char id[ID_LEN];
    int  index;

    if (supplierCount == 0) {
        printf("\nNo suppliers are currently registered.\n");
        return;
    }

    getValidString("\nEnter Supplier ID to search: ", id, ID_LEN);

    index = findSupplierByID(id);

    if (index == -1) {
        printf("\nSupplier with ID '%s' was not found.\n", id);
        return;
    }

    printSupplier(&suppliers[index]);
}

void searchSupplierByName(void)
{
    char searchName[NAME_LEN];
    int  i;
    int  found = 0;

    if (supplierCount == 0) {
        printf("\nNo suppliers are currently registered.\n");
        return;
    }

    getValidString("\nEnter Supplier Name to search: ", searchName, NAME_LEN);

    for (i = 0; i < supplierCount; i++) {
        if (strcmp(suppliers[i].name, searchName) == 0) {
            printSupplier(&suppliers[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nSupplier '%s' was not found.\n", searchName);
    }
}

void compareSuppliers(void)
{
    char id1[ID_LEN], id2[ID_LEN];
    int  index1, index2;

    if (supplierCount < 2) {
        printf("\nAt least two suppliers are required to compare.\n");
        return;
    }

    printf("\n========================================\n");
    printf("           COMPARE SUPPLIERS\n");
    printf("========================================\n");

    getValidString("Enter first Supplier ID: ", id1, ID_LEN);
    getValidString("Enter second Supplier ID: ", id2, ID_LEN);

    index1 = findSupplierByID(id1);
    index2 = findSupplierByID(id2);

    if (index1 == -1 || index2 == -1) {
        printf("\nOne or both Supplier IDs do not exist.\n");
        return;
    }

    if (strcmp(id1, id2) == 0) {
        printf("\nPlease enter two different suppliers.\n");
        return;
    }

    printf("\n====================================================\n");
    printf("              SUPPLIER COMPARISON\n");
    printf("====================================================\n");
    printf("%-20s %-20s %-20s\n", "Information",
           suppliers[index1].name, suppliers[index2].name);
    printf("----------------------------------------------------\n");
    printf("%-20s %-20s %-20s\n", "Supplier ID",
           suppliers[index1].id, suppliers[index2].id);
    printf("%-20s %-20s %-20s\n", "Email",
           suppliers[index1].email, suppliers[index2].email);
    printf("%-20s %-20s %-20s\n", "Telephone",
           suppliers[index1].telephone, suppliers[index2].telephone);
    printf("%-20s %-20s %-20s\n", "Town",
           suppliers[index1].town, suppliers[index2].town);
    printf("====================================================\n");
}

int getSupplierCount(void)
{
    return supplierCount;
}

Supplier* getSuppliers(void)
{
    return suppliers;
}