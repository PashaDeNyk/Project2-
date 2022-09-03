#include <iostream>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "background.h"
#include"structs.h"
#include"creeps.h"
#include"globalVar.h"
#include"score.h"
#pragma region CREEPS

int Ctt = 0;
int numCreep = 0;

void initCreepTextures(const char filename[],Creep* creeps)
{
	for (int i = 0; i < 25; i++)
	{
		creeps[i].tex = loadTextureFromFile(filename, &creeps[i].anim);
	}
}

void DestructCreeps(int i, Creep* creeps)
{
	if (creeps[i].health <= 0  and creeps[i].active or creeps[i].xWay > 1000 )
	{
		creeps[i].xAnim = -1;
		creeps[i].yAnim = -1;
		creeps[i].xWay = -100;
		creeps[i].yWay = -100;
		creeps[i].active = false;
		ScoreUpdate(25);
	}
}

void setCreep(int& max_count_creeps, Creep* creeps)
{
	if (numCreep < 5)
	{
		creeps[numCreep].xWay = 0;
		creeps[numCreep].yWay = 270;
		creeps[numCreep].xAnim = 75;
		creeps[numCreep].yAnim = 140;
		creeps[numCreep].health = 100;
		creeps[numCreep].active = true;
		numCreep++;
	}
	if (numCreep == 5)
		Ctt++;//Задержка
	if (numCreep > 4 and numCreep < 10 and Ctt == 2)
	{
		creeps[numCreep].xWay = 0;
		creeps[numCreep].yWay = 270;
		creeps[numCreep].xAnim = 75;
		creeps[numCreep].yAnim = 535;
		creeps[numCreep].health = 100;
		creeps[numCreep].active = true;
		numCreep++;
	}
}

void SetWayCreeps(int& x)
{
	if (x <= 1300)
		x++;
}

void HealthCreep(int i, Creep* creeps)
{
	SDL_SetRenderDrawColor(ren, 204, 0, 0, 255);
	creeps[i].damageRect = { creeps[i].xWay,creeps[i].yWay - 10,50,10 };
	SDL_RenderFillRect(ren, &creeps[i].damageRect);

	if (creeps[i].health > 0)
	{
		SDL_SetRenderDrawColor(ren, 0, 204, 0, 255);
		creeps[i].healthRect = { creeps[i].xWay,creeps[i].yWay - 10,creeps[i].health / 2,10 };
		SDL_RenderFillRect(ren, &creeps[i].healthRect);
	}

	SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
}

void AnimationCreeps(int& curpos, int i, Creep* creeps)
{
	int xAnim = creeps[i].xAnim;//Шаг картинки
	if (curpos == 15)
	{
		curpos = 0;
		xAnim = creeps[i].xAnim;
	}
	if (curpos / 5 == 0)
		xAnim += 75;
	creeps[i].anim = { xAnim,creeps[i].yAnim,42,84 };//Откуда брать кусочек картинки
}

void ClickCreep(int i, int mouse_x, int mouse_y, bool& mousebtdown, Creep* creeps)
{
	/*position*/if (mousebtdown == true and mouse_x >= creeps[i].xWay and mouse_x <= creeps[i].xWay + 42 and mouse_y >= creeps[i].yWay and mouse_y <= creeps[i].yWay + 84)
		/*health*/if (creeps[i].health > 0)
		{
			creeps[i].health = creeps[i].health - 50;
			mousebtdown = false;
		}
}

void DrawCreeps(int& curpos, int mouse_x, int mouse_y, bool& mousebtdown,int& max_count_creeps,Creep* creeps)
{
	for (int i = 0; i < numCreep; i++)
	{
		AnimationCreeps(curpos, i, creeps);
		SetWayCreeps(creeps[i].xWay); 
		SDL_Rect spawn = { creeps[i].xWay,creeps[i].yWay,42,84 };//Место спавна и размер самой картинки на фоне
		ClickCreep(i, mouse_x, mouse_y, mousebtdown, creeps);
		HealthCreep(i, creeps);

		//Где | Что | Размер чего-то | Где появиться что-то
		SDL_RenderCopy(ren, creeps[i].tex, &creeps[i].anim, &spawn);
		DestructCreeps(i, creeps);
		SDL_SetRenderDrawColor(ren,0,255,0,255);

	}
}
#pragma endregion
