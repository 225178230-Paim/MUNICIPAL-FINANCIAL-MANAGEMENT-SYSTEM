#include <stdio.h>
#include "assets.h"
#include "common.h"

static Asset assets[MAX_ASSETS];
static int assetCount = 0;

void addAsset(void)          { printf("[Asset module not yet implemented]\n"); }
void displayAssets(void)     { printf("[Asset module not yet implemented]\n"); }
void searchAssetByID(void)   { printf("[Asset module not yet implemented]\n"); }
void searchAssetByType(void) { printf("[Asset module not yet implemented]\n"); }

int getAssetCount(void)   { return assetCount; }
Asset* getAssets(void)    { return assets; }