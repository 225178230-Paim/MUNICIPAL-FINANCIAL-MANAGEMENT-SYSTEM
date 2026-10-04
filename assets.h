#ifndef ASSETS_H
#define ASSETS_H

#include "common.h" // This tells the code to look at Student 6's forms

#define MAX_ASSETS 100

// We deleted our struct because common.h already has one! 
// Now we just list the buttons.

void assetManagementMenu(void);
void addAsset(void);
void displayAssets(void);
void searchAssetByID(void);
void searchAssetByType(void);
int getAssetCount(void);
Asset* getAssets(void);

#endif