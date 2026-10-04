#ifndef ASSETS_H
#define ASSETS_H

#include "common.h"

void assetManagementMenu(void);
void addAsset(void);
void displayAssets(void);
void searchAssetByID(void);
void searchAssetByType(void);
int getAssetCount(void);
Asset* getAssets(void);

#endif