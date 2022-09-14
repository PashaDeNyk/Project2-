#pragma once
#include<iostream>
#include"structs.h"

void CheckLevelTower(int i, Tower* towers);

void DrawTower(int mouse_x, int mouse_y, int& countTower, bool& mousebtdown, bool& checkSpawn1, bool& checkSpawn2, bool& checkSpawn3, bool& checkSpawn4, Tower* towers, bool& load, int timerBullet, int max_count_creeps, Creep* creeps, bool& scoreBuying, Upgrade* up, Textures& tex, Score& score);