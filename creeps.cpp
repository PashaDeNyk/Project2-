#include <iostream>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "background.h"
#include"structs.h"
#include"creeps.h"
#include"globalVar.h"
#include"score.h"
#include"upgrade.h"

#pragma region CREEPS

int Ctt = 0;
int numCreep = 0;

void DestructCreeps(int i, Creep* creeps, Score& score, Textures& tex)
{
	if (creeps[i].health <= 0 and creeps[i].active or creeps[i].xWay > 1280)
	{
		creeps[i].active = false;
		creeps[i].xAnim = -100;
		creeps[i].yAnim = -100;
		//creeps[i].xWay = -100;
		//creeps[i].yWay = -100;
		ScoreUpdate(25, score);
	}
}

void setCreep(int& max_count_creeps, Creep* creeps)
{
	int typeCreep;

	typeCreep = rand() % 2 + 1;
	if (max_count_creeps < 10)
	{
		switch (typeCreep)
		{
		case 1:
		{
			creeps[numCreep].xWay = 0;
			creeps[numCreep].yWay = 270;
			creeps[numCreep].xAnim = 75;
			creeps[numCreep].yAnim = 140;
			creeps[numCreep].health = 100;
			creeps[numCreep].active = true;
			numCreep++;
			break;
		}
		case 2:
		{
			creeps[numCreep].xWay = 0;
			creeps[numCreep].yWay = 270;
			creeps[numCreep].xAnim = 75;
			creeps[numCreep].yAnim = 535;
			creeps[numCreep].health = 100;
			creeps[numCreep].active = true;
			numCreep++;
			break;
		}
		break;
		}
		max_count_creeps = numCreep;
	}
	else if (!creeps[0].active and !creeps[1].active and !creeps[2].active and !creeps[3].active and !creeps[4].active and !creeps[5].active and !creeps[6].active and !creeps[7].active and !creeps[8].active and !creeps[9].active)
	{
		max_count_creeps = 1;
		numCreep = 0;
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

void ClickCreep(int i, int mouse_x, int mouse_y, bool& mousebtdown, Creep* creeps, ClickUp& clickUp)
{
	if (creeps[i].health > 0 and mousebtdown == true and mouse_x >= creeps[i].xWay and mouse_x <= creeps[i].xWay + 42 and mouse_y >= creeps[i].yWay and mouse_y <= creeps[i].yWay + 84)
	{
		creeps[i].health -= clickUp.damage;
		mousebtdown = false;
	}
}

void DrawCreeps(int& curpos, int mouse_x, int mouse_y, bool& mousebtdown, int& max_count_creeps, Creep* creeps, ClickUp& clickUp, Textures& tex, Score& score)
{
	for (int i = 0; i < max_count_creeps; i++)
	{
		AnimationCreeps(curpos, i, creeps);
		if (creeps[i].active)
		{
			HealthCreep(i, creeps);
			SetWayCreeps(creeps[i].xWay);
		}
		SDL_Rect spawn = { creeps[i].xWay,creeps[i].yWay,42,84 };//Место спавна и размер самой картинки на фоне
		ButtonClickUpgrade(mouse_x, mouse_y, mousebtdown, clickUp, score);
		ClickCreep(i, mouse_x, mouse_y, mousebtdown, creeps, clickUp);
		SDL_RenderCopy(ren, tex.creep, &creeps[i].anim, &spawn);
		DestructCreeps(i, creeps, score, tex);
	}
}
#pragma endregion
