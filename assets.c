
#include <stdio.h>
#include <string.h>
#include "assets.h"
#include "common.h"

// 1. OUR LOCKERS (The array that stores all our Assets)
static Asset assets[MAX_ASSETS];
static int assetCount = 0;

// 2. A HELPER FUNCTION
// This reads what you type and removes the "Enter" key press.
static void readString(char *buffer, int size) {
    fgets(buffer, size, stdin);
    int i = 0;
    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
            break;
        }
        i++;
    }
}

// 3. FUNCTION TO ADD AN ASSET
void addAsset(void) {
    if (assetCount >= MAX_ASSETS) {
        printf("\nSorry, the asset register is full!\n");
        return;
    }

    Asset temp; // Create a temporary form to fill out

    printf("\n--- Add New Asset ---\n");

    // Ask for ID
    printf("Enter Asset ID: ");
    readString(temp.id, 20);
    if (strlen(temp.id) == 0) { // Check if they just pressed Enter
        printf("Error: ID cannot be empty!\n");
        return;
    }

    // Check if this ID already exists (using strcmp)
    for (int i = 0; i < assetCount; i++) {
        if (strcmp(assets[i].id, temp.id) == 0) {
            printf("Error: This ID already exists!\n");
            return;
        }
    }

    // Ask for Name
    printf("Enter Asset Name: ");
    readString(temp.name, 50);
    if (strlen(temp.name) == 0) {
        printf("Error: Name cannot be empty!\n");
        return;
    }

    // Ask for Type
    printf("Enter Asset Type (e.g., Vehicle, Computer): ");
    readString(temp.type, 30);

    // Ask for Value
    printf("Enter Purchase Value (N$): ");
    if (scanf("%lf", &temp.purchaseValue) != 1) {
        printf("Error: Invalid number!\n");
        while (getchar() != '\n'); // Clean the keyboard
        return;
    }
    if (temp.purchaseValue <= 0) { // Check for negative or zero money
        printf("Error: Value must be greater than zero!\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n'); // Clean up the Enter key

    // Ask for Department
    printf("Enter Department: ");
    readString(temp.department, 30);

    // Ask for Condition
    printf("Enter Condition (e.g., New, Good, Broken): ");
    readString(temp.condition, 20);

    // 4. SAVE IT TO THE LOCKER
    assets[assetCount] = temp;
    assetCount++; // Move to the next locker
    printf("Success! Asset added.\n");
}

// 5. FUNCTION TO SHOW ALL ASSETS
void displayAssets(void) {
    if (assetCount == 0) {
        printf("\nNo assets registered yet.\n");
        return;
    }

    printf("\n--- All Registered Assets ---\n");
    printf("%-10s %-20s %-15s %-15s %-15s %-10s\n", 
           "ID", "Name", "Type", "Value (N$)", "Department", "Condition");
    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < assetCount; i++) {
        printf("%-10s %-20s %-15s %-15.2f %-15s %-10s\n", 
               assets[i].id, assets[i].name, assets[i].type, 
               assets[i].purchaseValue, assets[i].department, assets[i].condition);
    }
}

// 6. FUNCTION TO SEARCH BY ID
void searchAssetByID(void) {
    char searchID[20];
    int found = 0;

    printf("\nEnter Asset ID to search: ");
    readString(searchID, 20);

    for (int i = 0; i < assetCount; i++) {
        // strcmp returns 0 if the two words are EXACTLY the same
        if (strcmp(assets[i].id, searchID) == 0) {
            printf("\nAsset Found!\n");
            printf("ID: %s\nName: %s\nType: %s\nValue: N$%.2f\nDept: %s\nCondition: %s\n",
                   assets[i].id, assets[i].name, assets[i].type, 
                   assets[i].purchaseValue, assets[i].department, assets[i].condition);
            found = 1;
            break; // Stop looking, we found it!
        }
    }

    if (found == 0) {
        printf("Sorry, no asset found with ID: %s\n", searchID);
    }
}

// 7. FUNCTION TO SEARCH BY TYPE
void searchAssetByType(void) {
    char searchType[30];
    int found = 0;

    printf("\nEnter Asset Type to search: ");
    readString(searchType, 30);

    for (int i = 0; i < assetCount; i++) {
        if (strcmp(assets[i].type, searchType) == 0) {
            printf("\nAsset Found!\n");
            printf("ID: %s\nName: %s\nType: %s\nValue: N$%.2f\nDept: %s\nCondition: %s\n",
                   assets[i].id, assets[i].name, assets[i].type, 
                   assets[i].purchaseValue, assets[i].department, assets[i].condition);
            found = 1;
        }
    }

    if (found == 0) {
        printf("Sorry, no asset found with type: %s\n", searchType);
    }
}

// 8. FUNCTIONS FOR REPORTS (Student 5 will use these)
int getAssetCount(void) {
    return assetCount;
}

Asset* getAssets(void) {
    return assets;
}

// 9. THE ASSET MENU
void assetManagementMenu(void) {
    int choice;

    do {
        printf("\n--- Asset Management ---\n");
        printf("1. Add Asset\n");
        printf("2. Display All Assets\n");
        printf("3. Search by ID\n");
        printf("4. Search by Type\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            choice = 0;
            continue;
        }
        while (getchar() != '\n'); 

        switch (choice) {
            case 1: addAsset(); break;
            case 2: displayAssets(); break;
            case 3: searchAssetByID(); break;
            case 4: searchAssetByType(); break;
            case 5: printf("Going back...\n"); break;
            default: printf("Invalid choice. Please enter 1 to 5.\n");
        }
    } while (choice != 5);
}