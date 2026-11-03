#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#include "common.h"

#define MAX_SUPPLIERS 100

void addSupplier(void);
void displaySuppliers(void);
void searchSupplierByID(void);
void searchSupplierByName(void);
int getSupplierCount(void);
Supplier* getSuppliers(void);

void compareSuppliers(void);

#endif
