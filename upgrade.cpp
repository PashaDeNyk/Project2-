#include<stdio.h>
#include"structs.h"
#include"globalvar.h"
#include"menu.h"

//������ ������������, ����� ���
void initUpgrade(Upgrade* up)
{
	for (int i = 0; i < 4; i++)
		up[i].textures = loadFont("lvl 1", "fonts\\Chava-Regular.ttf", { 0, 0, 200, 255 }, 25);
}

void UpdateUpgrade(int i, Tower* towers, Upgrade* up)
{
	char message[10];
	sprintf_s(message, "lvl %i", towers[i].level);
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
		SDL_SetRenderDrawColor(ren,0,0,180,255);
		SDL_RenderFillRect(ren, &up[i].button);
	}
}

void ButtonUpgrade(int mouse_x, int mouse_y, bool& mousebtdown, Tower* towers, Upgrade* up, int i)
{
	DrawButtonUpgrade(up);
	if (mousebtdown)
		//for (i = 0; i < 4; i++)
			if (mouse_x >= up[i].button.x and mouse_x <= up[i].button.x + up[i].button.w and mouse_y >= up[i].button.y and mouse_y <= up[i].button.y + up[i].button.h)
			{
				if (towers[i].level < 4)
				{
					towers[i].level++;
					UpdateUpgrade(i, towers, up);
				}
			}
}