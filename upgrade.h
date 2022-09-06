#pragma once
#include<stdio.h>
#include"structs.h"

void initUpgrade(Upgrade* up);

void UpdateUpgrade(int i, Tower* towers, Upgrade* up);

void ButtonUpgrade(int mouse_x, int mouse_y, bool& mousebtdown, Tower* towers, Upgrade* up, int i);

void DrawLevelUpgrade(Upgrade* up);