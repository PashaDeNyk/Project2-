#pragma once
#include<stdio.h>
#include"structs.h"

void initUpgrade(int i,Upgrade* up);

void UpdateUpgrade(int i, Tower* towers, Upgrade* up);

void DrawLevelUpgrade(Upgrade* up);

void DrawButtonUpgrade(Upgrade* up);

void ButtonUpgrade(int mouse_x, int mouse_y, bool& mousebtdown, Tower* towers, Upgrade* up, int i);