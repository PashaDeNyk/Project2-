#include<stdio.h>
#include"structs.h"
#include"globalvar.h"
#include"menu.h"
#include"score.h"
#include"tower.h"
#include"creeps.h"

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

void initClickUpgrade(ClickUp& clickUp)
{
	clickUp.textures = loadFont("lvl 1", "fonts\\Chava-Regular.ttf", { 0, 0, 200, 255 }, 25);
	clickUp.lvlRect = {1160,550,50,25};
	clickUp.drawRect = { 1220,550,40,40 };
	clickUp.level = 1;
	clickUp.damage = 10;
}

void UpdateClickUpgrade(ClickUp& clickUp)
{
	char message[15];
	sprintf_s(message, "lvl %d", clickUp.level);
	clickUp.textures = loadFont(message, "fonts\\Chava-Regular.ttf", { 0, 0, 200, 255 }, 25);
}

void DrawButtonClickUpgrade(ClickUp& clickUp)
{
	SDL_SetRenderDrawColor(ren, 0, 0, 180, 255);
	SDL_RenderFillRect(ren, &clickUp.drawRect);
}

void DrawLevelClickUpgrade(ClickUp& clickUp)
{
	SDL_RenderCopy(ren, clickUp.textures.tex, NULL, &clickUp.lvlRect);
}

void CheckClickLevel(ClickUp& clickUp)
{
	int lvl = clickUp.level;
	switch (lvl)
	{
	case 1:
	{
		clickUp.damage = 10;
		break;
	}
	case 2:
	{
		clickUp.damage = 15;
		break;
	}
	case 3:
	{
		clickUp.damage = 20;
		break;
	}
	case 4:
	{
		clickUp.damage = 25;
		break;
	}
	case 5:
	{
		clickUp.damage = 35;
		break;
	}
	}
}

void ButtonClickUpgrade(int mouse_x, int mouse_y, bool& mousebtdown, ClickUp& clickUp)
{
	if (mousebtdown and mouse_x >= clickUp.drawRect.x and mouse_x <= clickUp.drawRect.x + clickUp.drawRect.w and mouse_y >= clickUp.drawRect.y and mouse_y <= clickUp.drawRect.y + clickUp.drawRect.h)
	{
		ScoreCheck(25, buyUp);
		if (buyUp)
		{
			mousebtdown = false;
			if (clickUp.level < 5)
			{
				clickUp.level++;
				ScoreUpdate(-25);
				UpdateClickUpgrade(clickUp);
				CheckClickLevel(clickUp);
			}
		}
	}
}