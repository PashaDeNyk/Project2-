#pragma once
#include<stdio.h>

void initShopbgTextures(const char filename[]);

void SetShop();

void DrawShop(Textures& tex);

void setTypeTower(int buyType, int& countTower, Tower* towers);

void buildTower(int mouse_x, int mouse_y, int& countTower, bool& mousebtdown, bool& checkSpawn1, bool& checkSpawn2, bool& checkSpawn3, bool& checkSpawn4, Tower* towers,bool& load,Upgrade* up, Textures& tex);

void LoadTower(int mouse_x, int mouse_y, int& countTower, bool& mousebtdown, bool& checkSpawn1, bool& checkSpawn2, bool& checkSpawn3, bool& checkSpawn4, Tower* towers, bool& load, Upgrade* up, Textures& tex);

void buyingClickTower(int mouse_x, int mouse_y, bool& mousebtdown, bool& scoreBuying, Score& score);

void initPrice();

void DrawPrice();