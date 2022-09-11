#include<stdio.h>
#include"structs.h"
#include"globalvar.h"
#include"menu.h"
#include"score.h"
#include"tower.h"

bool buyUp = false;

void initUpgrade(int i, Upgrade* up)
{
	up[i].textures = loadFont("lvl 1", "fonts\\Chava-Regular.ttf", { 0, 0, 200, 255 }, 25);
}

void UpdateUpgrade(int i, Tower* towers, Upgrade* up)
{
	char message[15];
	sprintf_s(message, "lvl %d", towers[i].level);
	up[i].textures = loadFont(message, "fonts\\Chava-Regular.ttf", { 0, 0, 200, 255 }, 25);
}

void DrawLevelUpgrade(Upgrade* up)
{
	for (int i = 0; i < 4; i++)
	{
		SDL_RenderCopy(ren, up[i].textures.tex, NULL, &up[i].drawRect);
	}
}

void DrawButtonUpgrade(Upgrade* up)
{
	for (int i = 0; i < 4; i++)
	{
		SDL_SetRenderDrawColor(ren, 0, 0, 180, 255);
		SDL_RenderFillRect(ren, &up[i].button);
	}
}

void ButtonUpgrade(int mouse_x, int mouse_y, bool& mousebtdown, Tower* towers, Upgrade* up, int i)
{
	if (mousebtdown and mouse_x >= up[i].button.x and mouse_x <= up[i].button.x + up[i].button.w and mouse_y >= up[i].button.y and mouse_y <= up[i].button.y + up[i].button.h)
	{
		ScoreCheck(25, buyUp);
		if (buyUp)
		{
			mousebtdown = false;
			if (towers[i].level < 4)
			{
				towers[i].level++;
				ScoreUpdate(-25);
				UpdateUpgrade(i, towers, up);
				CheckLevelTower(i, towers);
			}
		}
	}
}