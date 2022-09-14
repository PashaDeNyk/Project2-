#include<iostream>
#include<SDL.h>
#include<SDL_image.h>

#include"structs.h"
#include"background.h"
#include"globalvar.h"
#include"shop.h"
#include"upgrade.h"
#include"bullet.h"

#pragma region TOWER
int num = 0;

void CheckLevelTower(int i, Tower* towers)
{
	int lvl = towers[i].level;
	switch (lvl)
	{
	case 1:
	{
		towers[i].damage = 25;
		break;
	}
	case 2:
	{
		towers[i].damage = 35;
		break;
	}
	case 3:
	{
		towers[i].damage = 40;
		break;
	}
	case 4:
	{
		towers[i].damage = 50;
		break;
	}
	}
}

//Чек на занятое место
void DrawTower(int mouse_x, int mouse_y, int& countTower, bool& mousebtdown, bool& checkSpawn1, bool& checkSpawn2, bool& checkSpawn3, bool& checkSpawn4, Tower* towers, bool& load, int timerBullet, int max_count_creeps, Creep* creeps, bool& scoreBuying, Upgrade* up, Textures& tex,Score& score)
{
	for (int i = 0; i < 4; i++)
	{
		CheckDistance(timerBullet, max_count_creeps, creeps, towers);
		DrawLevelUpgrade(up);
		DrawButtonUpgrade(up);
		ButtonUpgrade(mouse_x, mouse_y, mousebtdown, towers, up, i,score);
		//Где(поверхность) | Что(Текстура) | Размер чего-то(NULL если не кусочек) | Где появиться что-то(NULL вся поверхность)
		SDL_RenderCopy(ren, tex.tower, &towers[i].anim, &towers[i].spawn);
	}
}
#pragma endregion