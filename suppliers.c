#include <stdio.h>
#include "suppliers.h"
#include "common.h"

static Supplier suppliers[MAX_SUPPLIERS];
static int supplierCount = 0;

void addSupplier(void)          { printf("[Supplier module not yet implemented]\n"); }
void displaySuppliers(void)     { printf("[Supplier module not yet implemented]\n"); }
void searchSupplierByID(void)   { printf("[Supplier module not yet implemented]\n"); }
void searchSupplierByName(void) { printf("[Supplier module not yet implemented]\n"); }

int getSupplierCount(void)   { return supplierCount; }
Supplier* getSuppliers(void) { return suppliers; }