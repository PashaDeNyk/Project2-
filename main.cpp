#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include"structs.h"
#include "background.h"
#include"creeps.h"
#include"initialization.h"
#include"globalvar.h"
#include"tower.h"
#include"menu.h"
#include"save_and_load.h"
#include"score.h"
#include"shop.h"
#include"bullet.h"
#include"upgrade.h"
#include"healthPlayer.h"

void MissClicks(bool& mousebtdown)
{
	if (mousebtdown)
	{
		mousebtdown = false;
	}
}

void Draw(int& curpos, int mouse_x, int mouse_y, bool& mousebtdown, int& countTower, bool& checkSpawn1, bool& checkSpawn2, bool& checkSpawn3, bool& checkSpawn4, int& max_count_creeps, int& timerBullet, Creep* creeps, Tower* towers, bool& load, bool scoreBuying, Upgrade* up, ClickUp& clickUp, Textures& tex, Score& score,healthPlayer& player)
{
	ChangedBackground();
	DrawTower(mouse_x, mouse_y, countTower, mousebtdown, checkSpawn1, checkSpawn2, checkSpawn3, checkSpawn4, towers, load, timerBullet, max_count_creeps, creeps, scoreBuying, up, tex,score);
	DrawCreeps(curpos, mouse_x, mouse_y, mousebtdown, max_count_creeps, creeps, clickUp, tex,score,player);
	CheckDistance(timerBullet, max_count_creeps, creeps, towers);
	DrawScore(score);
	DrawShop(tex);
	buyingClickTower(mouse_x, mouse_y, mousebtdown, scoreBuying,score);
	buildTower(mouse_x, mouse_y, countTower, mousebtdown, checkSpawn1, checkSpawn2, checkSpawn3, checkSpawn4, towers, load, up,tex);
	DrawButtonClickUpgrade(clickUp);
	DrawLevelClickUpgrade(clickUp);
	DrawHealth(player);
	SDL_RenderPresent(ren);
	MissClicks(mousebtdown);
	SDL_Delay(1000 / 60);
	curpos++;
}

int main(int argc, char* argv[])
{
	Init();
	srand(time(NULL));

	Creep creeps[25];
	Tower towers[4];
	Upgrade up[4];
	ClickUp clickUp;
	Score score;
	Textures tex;
	healthPlayer player;

	initTowerTextures("images/Tower.png", tex);
	initCreepTextures("images/creepsbg.png", tex);
	initScore(score);
	initShopbgTextures("images/shopbg.png");
	for (size_t i = 0; i < 4; i++)
	initBulletTextures("images/cannonball.png", towers[i].bullet);
	initPrice();
	initClickUpgrade(clickUp);
	initHealth(player);

	int tt = 59;
	int mouse_x = 0, mouse_y = 0;
	int anpos = 0;
	int max_count_creeps = 1;
	bool mousebtdown = false;
	bool rightbtdown = false;
	bool isRunning = true;
	bool startgame = false;
	bool startapp = true;
	bool bgcreeps = false;
	bool bgmenu = true;
	int i = 0;
	int countTower = 0;
	bool checkSpawn4 = false;
	bool checkSpawn1 = false;
	bool checkSpawn2 = false;
	bool checkSpawn3 = false;
	int timerBullet = 0;
	bool load = false;
	bool scoreBuying = false;
	bool startInfo = false;
	bool bgInfo = true;
	int point = 0;
	SDL_Event ev;

	while (isRunning)
	{
		while (SDL_PollEvent(&ev))
		{
			switch (ev.type)
			{

			case SDL_QUIT:
			{
				isRunning = false;
				break;
			}
			case SDL_MOUSEMOTION:
			{
				mouse_x = ev.motion.x;
				mouse_y = ev.motion.y;
				break;
			}
			case SDL_MOUSEBUTTONDOWN:
				if (ev.button.button == SDL_BUTTON_LEFT)
				{
					mouse_x = ev.button.x;
					mouse_y = ev.button.y;
					mousebtdown = true;
				}
				else if (ev.button.button == SDL_BUTTON_RIGHT)
				{
					rightbtdown = true;
				}
				break;
			case SDL_KEYDOWN:
				switch (ev.key.keysym.scancode)
				{
				case SDL_SCANCODE_ESCAPE:
				{
					if (startInfo)
					{
						startInfo = false;
						startapp = true;
					}
					break;
				}
				break;
				case SDL_SCANCODE_F5:
				{
					SaveBin(towers,score,player,clickUp);
					break;
				}
				case SDL_SCANCODE_F6:
				{
					load = true;
					LoadBin(towers,score,player, clickUp);
					ScoreUpdate(point, score);
					UpdateHealth(player);
					LoadTower(mouse_x, mouse_y, countTower, mousebtdown, checkSpawn1, checkSpawn2, checkSpawn3, checkSpawn4, towers, load, up, tex);
					UpdateUpgrade(i, towers, up);
					UpdateClickUpgrade(clickUp);
					break;
				}
				}
			}
		}
		if (startapp)
		{
			if (bgmenu)
			{
				initBackgroundsTextures("images/bgmenu.jpg");
				bgmenu = false;
			}
			MenuClick(mouse_x, mouse_y, startgame, startapp, bgcreeps, mousebtdown, isRunning, startInfo);
			drawMenu(i, mouse_x, mouse_y, mousebtdown, startapp, startgame, bgcreeps);
			MenuDestroy();
			SDL_RenderPresent(ren);
		}
		if (startInfo)
		{
			if (startapp)
			{
				MenuDestroy();
				startapp = false;
			}
			getInfo();
		}
		if (startgame)
		{
			if (startapp)
				startapp = false;
			if (bgcreeps)
			{
				initBackgroundsTextures("images/bg.jpg");
				bgcreeps = false;
			}
			tt++;
			if (tt % 60 == 0)
				setCreep(max_count_creeps, creeps);
			Draw(anpos, mouse_x, mouse_y, mousebtdown, countTower, checkSpawn1, checkSpawn2, checkSpawn3, checkSpawn4, max_count_creeps, timerBullet, creeps, towers, load, scoreBuying, up, clickUp, tex,score, player);
		}

	}
	TTF_CloseFont(0);
	DeInit(0);
	SDL_Quit();
	return 0;
}