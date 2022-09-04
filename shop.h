#pragma once
#include<stdio.h>

void initShopbgTextures();

void initShopTextures(Tower* towers);

void SetShop();

void DrawShop();


void setTypeTower(int buyType, int& countTower, Tower* towers);

void buildTower(int mouse_x, int mouse_y, int& countTower, bool& mousebtdown, bool& checkSpawn1, bool& checkSpawn2, bool& checkSpawn3, bool& checkSpawn4, Tower* towers,bool& load);

void buyingClickTower(int mouse_x, int mouse_y, bool& mousebtdown, bool& scoreBuying);

void initPrice();

void DrawPrice();
