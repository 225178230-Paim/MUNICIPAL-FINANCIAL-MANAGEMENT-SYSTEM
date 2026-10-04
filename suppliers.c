#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "suppliers.h"

/* Array to store suppliers */
static Supplier suppliers[MAX_SUPPLIERS];

/* Number of suppliers currently stored */
static int supplierCount = 0;


/* ---------------------------------------------------------
   CLEAR INPUT BUFFER
   --------------------------------------------------------- */
void clearInputBuffer(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {
        /* Clear remaining input */
    }
}


/* ---------------------------------------------------------
   FIND SUPPLIER BY ID
   Returns array position if found.
   Returns -1 if supplier does not exist.
   --------------------------------------------------------- */
int findSupplierByID(int id)
{
    int i;

    for (i = 0; i < supplierCount; i++)
    {
        if (suppliers[i].supplierID == id)
        {
            return i;
        }
    }

    return -1;
}


/* ---------------------------------------------------------
   ADD SUPPLIER
   --------------------------------------------------------- */
void addSupplier(void)
{
    Supplier newSupplier;

    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("\n========================================\n");
        printf("Supplier storage is full.\n");
        printf("Maximum suppliers: %d\n", MAX_SUPPLIERS);
        printf("========================================\n");
        return;
    }

    printf("\n========================================\n");
    printf("          ADD NEW SUPPLIER\n");
    printf("========================================\n");

    /* Supplier ID */
    while (1)
    {
        printf("Enter Supplier ID: ");

        if (scanf("%d", &newSupplier.supplierID) != 1)
        {
            printf("Invalid ID. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        if (newSupplier.supplierID <= 0)
        {
            printf("Supplier ID must be greater than 0.\n");
            continue;
        }

        if (findSupplierByID(newSupplier.supplierID) != -1)
        {
            printf("Supplier ID already exists.\n");
            continue;
        }

        break;
    }


    /* Supplier Name */
    while (1)
    {
        printf("Enter Supplier Name: ");

        fgets(newSupplier.name,
              sizeof(newSupplier.name),
              stdin);

        newSupplier.name[
            strcspn(newSupplier.name, "\n")
        ] = '\0';

        if (strlen(newSupplier.name) == 0)
        {
            printf("Supplier name cannot be empty.\n");
        }
        else
        {
            break;
        }
    }


    /* Email */
    while (1)
    {
        printf("Enter Email: ");

        fgets(newSupplier.email,
              sizeof(newSupplier.email),
              stdin);

        newSupplier.email[
            strcspn(newSupplier.email, "\n")
        ] = '\0';

        if (strlen(newSupplier.email) == 0)
        {
            printf("Email cannot be empty.\n");
        }
        else if (strchr(newSupplier.email, '@') == NULL)
        {
            printf("Invalid email. Email must contain '@'.\n");
        }
        else
        {
            break;
        }
    }


    /* Telephone */
    while (1)
    {
        printf("Enter Telephone Number: ");

        fgets(newSupplier.telephone,
              sizeof(newSupplier.telephone),
              stdin);

        newSupplier.telephone[
            strcspn(newSupplier.telephone, "\n")
        ] = '\0';

        if (strlen(newSupplier.telephone) == 0)
        {
            printf("Telephone number cannot be empty.\n");
        }
        else
        {
            break;
        }
    }


    /* Location */
    while (1)
    {
        printf("Enter Town/Location: ");

        fgets(newSupplier.location,
              sizeof(newSupplier.location),
              stdin);

        newSupplier.location[
            strcspn(newSupplier.location, "\n")
        ] = '\0';

        if (strlen(newSupplier.location) == 0)
        {
            printf("Location cannot be empty.\n");
        }
        else
        {
            break;
        }
    }


    /* Store supplier in array */
    suppliers[supplierCount] = newSupplier;
    supplierCount++;

    printf("\n----------------------------------------\n");
    printf("Supplier added successfully!\n");
    printf("Supplier ID: %d\n", newSupplier.supplierID);
    printf("Supplier Name: %s\n", newSupplier.name);
    printf("----------------------------------------\n");
}


/* ---------------------------------------------------------
   DISPLAY ALL SUPPLIERS
   --------------------------------------------------------- */
void displaySuppliers(void)
{
    int i;

    if (supplierCount == 0)
    {
        printf("\nNo suppliers have been registered yet.\n");
        return;
    }

    printf("\n===============================================================\n");
    printf("                    REGISTERED SUPPLIERS\n");
    printf("===============================================================\n");

    printf("%-10s %-25s %-30s %-18s %-20s\n",
           "ID",
           "NAME",
           "EMAIL",
           "TELEPHONE",
           "LOCATION");

    printf("---------------------------------------------------------------"
           "--------------------\n");

    for (i = 0; i < supplierCount; i++)
    {
        printf("%-10d %-25s %-30s %-18s %-20s\n",
               suppliers[i].supplierID,
               suppliers[i].name,
               suppliers[i].email,
               suppliers[i].telephone,
               suppliers[i].location);
    }

    printf("===============================================================\n");
    printf("Total Suppliers: %d\n", supplierCount);
}


/* ---------------------------------------------------------
   SEARCH SUPPLIER
   Search by Supplier ID or Supplier Name.
   --------------------------------------------------------- */
void searchSupplier(void)
{
    int choice;
    int id;
    int index;
    char searchName[100];
    int found = 0;
    int i;

    if (supplierCount == 0)
    {
        printf("\nNo suppliers are currently registered.\n");
        return;
    }

    printf("\n========================================\n");
    printf("          SEARCH SUPPLIER\n");
    printf("========================================\n");
    printf("1. Search by Supplier ID\n");
    printf("2. Search by Supplier Name\n");
    printf("3. Return\n");
    printf("----------------------------------------\n");
    printf("Enter choice: ");

    if (scanf("%d", &choice) != 1)
    {
        printf("Invalid choice.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    /* Search by ID */
    if (choice == 1)
    {
        printf("Enter Supplier ID: ");

        if (scanf("%d", &id) != 1)
        {
            printf("Invalid ID.\n");
            clearInputBuffer();
            return;
        }

        clearInputBuffer();

        index = findSupplierByID(id);

        if (index == -1)
        {
            printf("\nSupplier with ID %d was not found.\n", id);
            return;
        }

        printf("\n========================================\n");
        printf("          SUPPLIER FOUND\n");
        printf("========================================\n");
        printf("Supplier ID : %d\n", suppliers[index].supplierID);
        printf("Name        : %s\n", suppliers[index].name);
        printf("Email       : %s\n", suppliers[index].email);
        printf("Telephone   : %s\n", suppliers[index].telephone);
        printf("Location    : %s\n", suppliers[index].location);
        printf("========================================\n");
    }

    /* Search by name */
    else if (choice == 2)
    {
        printf("Enter Supplier Name: ");

        fgets(searchName,
              sizeof(searchName),
              stdin);

        searchName[
            strcspn(searchName, "\n")
        ] = '\0';

        if (strlen(searchName) == 0)
        {
            printf("Search name cannot be empty.\n");
            return;
        }

        for (i = 0; i < supplierCount; i++)
        {
            if (strcmp(suppliers[i].name, searchName) == 0)
            {
                printf("\n========================================\n");
                printf("          SUPPLIER FOUND\n");
                printf("========================================\n");
                printf("Supplier ID : %d\n", suppliers[i].supplierID);
                printf("Name        : %s\n", suppliers[i].name);
                printf("Email       : %s\n", suppliers[i].email);
                printf("Telephone   : %s\n", suppliers[i].telephone);
                printf("Location    : %s\n", suppliers[i].location);
                printf("========================================\n");

                found = 1;
                break;
            }
        }

        if (!found)
        {
            printf("\nSupplier '%s' was not found.\n", searchName);
        }
    }

    else if (choice == 3)
    {
        return;
    }

    else
    {
        printf("Invalid choice.\n");
    }
}


/* ---------------------------------------------------------
   COMPARE TWO SUPPLIERS
   --------------------------------------------------------- */
void compareSuppliers(void)
{
    int id1;
    int id2;
    int index1;
    int index2;

    if (supplierCount < 2)
    {
        printf("\nAt least two suppliers are required to compare them.\n");
        return;
    }

    printf("\n========================================\n");
    printf("          COMPARE SUPPLIERS\n");
    printf("========================================\n");

    printf("Enter first Supplier ID: ");

    if (scanf("%d", &id1) != 1)
    {
        printf("Invalid Supplier ID.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    printf("Enter second Supplier ID: ");

    if (scanf("%d", &id2) != 1)
    {
        printf("Invalid Supplier ID.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    index1 = findSupplierByID(id1);
    index2 = findSupplierByID(id2);

    if (index1 == -1 || index2 == -1)
    {
        printf("\nOne or both Supplier IDs do not exist.\n");
        return;
    }

    if (id1 == id2)
    {
        printf("\nPlease enter two different suppliers.\n");
        return;
    }

    printf("\n====================================================\n");
    printf("                 SUPPLIER COMPARISON\n");
    printf("====================================================\n");

    printf("%-20s %-25s %-25s\n",
           "Information",
           suppliers[index1].name,
           suppliers[index2].name);

    printf("----------------------------------------------------\n");

    printf("%-20s %-25d %-25d\n",
           "Supplier ID",
           suppliers[index1].supplierID,
           suppliers[index2].supplierID);

    printf("%-20s %-25s %-25s\n",
           "Email",
           suppliers[index1].email,
           suppliers[index2].email);

    printf("%-20s %-25s %-25s\n",
           "Telephone",
           suppliers[index1].telephone,
           suppliers[index2].telephone);

    printf("%-20s %-25s %-25s\n",
           "Location",
           suppliers[index1].location,
           suppliers[index2].location);

    printf("====================================================\n");
}


/* ---------------------------------------------------------
   SUPPLIER MENU
   --------------------------------------------------------- */
void supplierMenu(void)
{
    int choice;

    do
    {
        printf("\n\n========================================\n");
        printf("          SUPPLIER MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Compare Suppliers\n");
        printf("5. Return to Main Menu\n");
        printf("========================================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\nInvalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        switch (choice)
        {
            case 1:
                addSupplier();
                break;

            case 2:
                displaySuppliers();
                break;

            case 3:
                searchSupplier();
                break;

            case 4:
                compareSuppliers();
                break;

            case 5:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice. Please select 1-5.\n");
        }

    } while (choice != 5);
}