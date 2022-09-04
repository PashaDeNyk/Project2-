#include<iostream>
#include<SDL.h>
#include<SDL_image.h>

#include"structs.h"
#include"background.h"
#include"globalvar.h"
#include"shop.h"

#pragma region TOWER

//Tower towers[4];

int num = 0;

void initTowerTextures(const char filename[], Tower* towers)
{
	for (int i = 0; i < 4; i++)
	{
		towers[i].tex = loadTextureFromFile(filename, &towers[i].anim);
	}
}

void initBulletTextures(const char filename[], Tower* towers)
{
	for (int i = 0; i < 4; i++)
	{
		towers[i].shot_tex = loadTextureFromFile(filename, &towers[i].shot_anim);
	}
}

int Distance(Creep creep, Tower tower)
{
	return sqrt((creep.xWay - tower.spawn.x) * (creep.xWay - tower.spawn.x) + (creep.yWay - tower.spawn.y) * (creep.yWay - tower.spawn.y));
}

//Отрисовка пули если она активна, если нет то она пропадает за задником
void WayBullet(Creep& creep, Tower& tower)
{
	float angle = atan2(creep.yWay - tower.spawn.y, creep.xWay - tower.spawn.x);
	//if (tower.bullet.x != creep.xWay)
		tower.bullet.x += cos(angle)*2;
	//if (tower.bullet.y != creep.yWay)
		tower.bullet.y += sin(angle)*2;
	//if (Distance(creep, tower) >= tower.dist)
	if (tower.bullet.x >= creep.xWay and tower.bullet.x <= creep.xWay + 42 and tower.bullet.y >= creep.yWay and tower.bullet.y <= creep.yWay + 84)
	{
		//Отнимаем хп у крипа
		tower.bullet.x = (tower.spawn.x + tower.spawn.w / 2);
		tower.bullet.y = (tower.spawn.y + tower.spawn.h / 2);
		creep.health -= 1;
		tower.lock = 101;
	}
	//Отрисовываем
	SDL_RenderCopy(ren, tower.shot_tex, NULL, &tower.bullet);
}

void CheckDistance(int& timerBullet, int max_count_creeps, Creep* creeps, Tower* towers)
{
	for (int k = 0; k < 4; k++)
	{
		for (int i = 0; i < max_count_creeps; i++)
		{
			if (creeps[i].active)
			{
				towers[k].dist = Distance(creeps[i], towers[k]);
				//printf("%i", towers[k].dist);
				//system("cls");
				if (towers[k].dist <= towers[k].rad and towers[k].lock == 101)
				{
					
					towers[k].lock = i;
					timerBullet++;
					//WayBullet(creeps[towers[k].lock], towers[k]);
				}
				if (towers[k].lock != 101)
				{
					WayBullet(creeps[towers[k].lock], towers[k]);
				}
			}
		}
	}
}

//Чек на занятое место
void DrawTower(int mouse_x, int mouse_y, int& countTower, bool& mousebtdown, bool& checkSpawn1, bool& checkSpawn2, bool& checkSpawn3, bool& checkSpawn4, Tower* towers, bool& load, int timerBullet, int max_count_creeps, Creep* creeps,bool& scoreBuying,Upgrade* up)
{
	for (int i = 0; i < 4; i++)
	{
		DrawShop();
		buyingClickTower(mouse_x, mouse_y, mousebtdown, scoreBuying);
		buildTower(mouse_x, mouse_y, countTower, mousebtdown, checkSpawn1, checkSpawn2, checkSpawn3, checkSpawn4, towers, load,up);
		CheckDistance(timerBullet, max_count_creeps, creeps, towers);
		SDL_SetRenderDrawColor(ren, 0, 0, 180, 255);
		SDL_RenderFillRect(ren, &up[i].drawRect);
		//Где(поверхность) | Что(Текстура) | Размер чего-то(NULL если не кусочек) | Где появиться что-то(NULL вся поверхность)
		SDL_RenderCopy(ren, towers[i].tex, &towers[i].anim, &towers[i].spawn);
	}
}
#pragma endregion