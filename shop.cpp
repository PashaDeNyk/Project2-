#include<stdio.h>
#include"globalvar.h"
#include"structs.h"
#include"background.h"
#include"score.h"
#include"menu.h"
#include"upgrade.h"
#include"tower.h"

Shop shop[3];
Shopbg shopbg;
Places place;
Price price[3];

bool buy = false;
int buyType = 0;
int spawn = 0;

void initShopbgTextures(const char filename[])
{
	shopbg.tex = loadTextureFromFile(filename, &shopbg.anim);
	shopbg.anim = { 406,236,150,34 };
	shopbg.spawn = { 0,500,1280,220 };
}

void SetShop()
{
	shop[0].anim = { 0,0,150,105 };
	shop[0].spawn = { 100,550,100,100 };

	shop[1].anim = { 175,0,150,105 };
	shop[1].spawn = { 300,550,100,100 };

	shop[2].anim = { 355,0,150,105 };
	shop[2].spawn = { 500,550,100,100 };
}

void setTypeTower(int buyType, int& countTower, Tower* towers)
{
	switch (buyType)
	{
	case 1:
	{
		towers[countTower].anim = { 0,0,150,105 };
		towers[countTower].lock = -1;
		towers[countTower].index = towers[countTower].index + 1;
		towers[countTower].bullet.x = towers[countTower].spawn.x + towers[countTower].spawn.w / 2;
		towers[countTower].bullet.y = towers[countTower].spawn.y + towers[countTower].spawn.h / 2;
		buyType = 0;
		countTower++;
		break;
	}
	case 2:
	{
		towers[countTower].anim = { 175,0,150,105 };
		towers[countTower].lock = -1;
		towers[countTower].index = towers[countTower].index + 2;
		towers[countTower].bullet.x = towers[countTower].spawn.x + towers[countTower].spawn.w / 2;
		towers[countTower].bullet.y = towers[countTower].spawn.y + towers[countTower].spawn.h / 2;
		buyType = 0;
		countTower++;
		break;
	}
	case 3:
	{
		towers[countTower].anim = { 355,0,150,105 };
		towers[countTower].lock = -1;
		towers[countTower].index = towers[countTower].index + 3;
		towers[countTower].bullet.x = towers[countTower].spawn.x + towers[countTower].spawn.w / 2;
		towers[countTower].bullet.y = towers[countTower].spawn.y + towers[countTower].spawn.h / 2;
		buyType = 0;
		countTower++;
		break;
	}
	}

}

//Определение места постройки башни
void buildTower(int mouse_x, int mouse_y, int& countTower, bool& mousebtdown, bool& checkSpawn1, bool& checkSpawn2, bool& checkSpawn3, bool& checkSpawn4, Tower* towers, bool& load, Upgrade* up, Textures& tex)
{
	if (buy == true)
	{
		if (checkSpawn1 == false and mousebtdown == true and mouse_x >= place.p1.x and mouse_x <= place.p1.x + place.p1.w and mouse_y >= place.p1.y and mouse_y <= place.p1.y + place.p1.h or spawn == 1)
		{
			checkSpawn1 = true;
			mousebtdown = false;
			buy = false;
			towers[countTower].spawn = { 340,183,150,105 };
			up[countTower].button = { 500,265,20,20 };
			up[countTower].drawRect = { 500,225,50,25 };
			towers[countTower].level = towers[countTower].level;
			towers[countTower].index = 10;
			towers[countTower].active = true;
			CheckLevelTower(countTower, towers);
			initUpgrade(countTower, up, tex);
			setTypeTower(buyType, countTower, towers);
		}
		else if (checkSpawn2 == false and mousebtdown == true and mouse_x >= place.p2.x and mouse_x <= place.p2.x + place.p2.w and mouse_y >= place.p2.y and mouse_y <= place.p2.y + place.p2.h or spawn == 2)
		{
			checkSpawn2 = true;
			mousebtdown = false;
			buy = false;
			towers[countTower].spawn = { 923,180,150,105 };
			up[countTower].button = { 1083,265,20,20 };
			up[countTower].drawRect = { 1083,225,50,25 };
			towers[countTower].level = towers[countTower].level;
			towers[countTower].index = 20;
			towers[countTower].active = true;
			CheckLevelTower(countTower, towers);
			initUpgrade(countTower, up, tex);
			setTypeTower(buyType, countTower, towers);
		}

		else if (checkSpawn3 == false and mousebtdown == true and mouse_x >= place.p3.x and mouse_x <= place.p3.x + place.p3.w and mouse_y >= place.p3.y and mouse_y <= place.p3.y + place.p3.h or spawn == 3)
		{
			checkSpawn3 = true;
			mousebtdown = false;
			buy = false;
			towers[countTower].spawn = { 128,363,150,105 };
			up[countTower].button = { 288,448,20,20 };
			up[countTower].drawRect = { 288,408,50,25 };
			towers[countTower].level = towers[countTower].level;
			towers[countTower].index = 30;
			towers[countTower].active = true;
			CheckLevelTower(countTower, towers);
			initUpgrade(countTower, up, tex);
			setTypeTower(buyType, countTower, towers);
		}

		else if (checkSpawn4 == false and mousebtdown == true and mouse_x >= place.p4.x and mouse_x <= place.p4.x + place.p4.w and mouse_y >= place.p4.y and mouse_y <= place.p4.y + place.p4.h or spawn == 4)
		{
			checkSpawn4 = true;
			mousebtdown = false;
			buy = false;
			towers[countTower].spawn = { 594,363,150,105 };
			up[countTower].button = { 754,448,20,20 };
			up[countTower].drawRect = { 754,408,50,25 };
			towers[countTower].level = towers[countTower].level;
			towers[countTower].index = 40;
			towers[countTower].active = true;
			CheckLevelTower(countTower, towers);
			initUpgrade(countTower, up, tex);
			setTypeTower(buyType, countTower, towers);
		}
	}
}

void LoadTower(int mouse_x, int mouse_y, int& countTower, bool& mousebtdown, bool& checkSpawn1, bool& checkSpawn2, bool& checkSpawn3, bool& checkSpawn4, Tower* towers, bool& load, Upgrade* up, Textures& tex)
{
	if (load)
	{
		buy = true;
		int placeT = 0;
		int typeT = 0;
		for (int i = 0; i < 4; i++)
		{
			placeT = towers[i].index / 10;//место для башни целое от 10
			typeT = towers[i].index % 10;//тип башни остаток от 10
			switch (placeT)
			{
			case 1:
			{
				spawn = 1;
				checkSpawn1 = true;
				break;
			}
			case 2:
			{
				spawn = 2;
				checkSpawn2 = true;
				break;
			}
			case 3:
			{
				spawn = 3;
				checkSpawn3 = true;
				break;
			}
			case 4:
			{
				spawn = 4;
				checkSpawn4 = true;
				break;
			}
			break;
			}

			setTypeTower(typeT, i, towers);
			buildTower(mouse_x, mouse_y, countTower, mousebtdown, checkSpawn1, checkSpawn2, checkSpawn3, checkSpawn4, towers, load, up, tex);
			spawn = 0;
		}
		load = false;
	}

}

void buyingClickTower(int mouse_x, int mouse_y, bool& mousebtdown, bool& scoreBuying,Score& score)
{
	if (mousebtdown == true and mouse_x >= shop[0].spawn.x and mouse_x <= shop[0].spawn.x + shop[0].spawn.w and mouse_y >= shop[0].spawn.y and mouse_y <= shop[0].spawn.y + shop[0].spawn.h)
	{
		ScoreCheck(price[0].cost, scoreBuying,score);
		if (scoreBuying)
		{
			buy = true;
			buyType = 1;
			ScoreUpdate(-price[0].cost,score);
			mousebtdown = false;
		}
		scoreBuying = false;
		mousebtdown = false;
	}
	else
		if (mousebtdown == true and mouse_x >= shop[1].spawn.x and mouse_x <= shop[1].spawn.x + shop[1].spawn.w and mouse_y >= shop[1].spawn.y and mouse_y <= shop[1].spawn.y + shop[1].spawn.h)
		{
			ScoreCheck(price[1].cost, scoreBuying,score);
			if (scoreBuying)
			{
				buy = true;
				buyType = 2;
				ScoreUpdate(-price[1].cost,score);
				mousebtdown = false;
			}
			scoreBuying = false;
			mousebtdown = false;
		}
		else
			if (mousebtdown == true and mouse_x >= shop[2].spawn.x and mouse_x <= shop[2].spawn.x + shop[2].spawn.w and mouse_y >= shop[2].spawn.y and mouse_y <= shop[2].spawn.y + shop[2].spawn.h)
			{
				ScoreCheck(price[2].cost, scoreBuying,score);
				if (scoreBuying)
				{
					buy = true;
					buyType = 3;
					ScoreUpdate(-price[2].cost,score);
					mousebtdown = false;
				}
				scoreBuying = false;
				mousebtdown = false;
			}
}

void initPrice()
{
	for (int i = 0, k = 100, x = 100; i < 3; i++, k += 100, x += 200)
	{
		price[i].cost = k;
		price[i].drawRect = { x,660,100,35 };
		char cost[10];
		sprintf_s(cost, "%i", price[i].cost);
		price[i].textures = loadFont(cost, "fonts\\Chava-Regular.ttf", { 0, 0, 200, 255 }, 25);
	}
}

void DrawPrice()
{
	for (int i = 0; i < 3; i++)
	{
		SDL_RenderCopy(ren, price[i].textures.tex, NULL, &price[i].drawRect);
	}
}

void DrawShop(Textures& tex)
{
	SDL_RenderCopy(ren, shopbg.tex, &shopbg.anim, &shopbg.spawn);
	SetShop();
	DrawPrice();
	for (int i = 0; i < 3; i++)
	{
		SDL_RenderCopy(ren, tex.tower, &shop[i].anim, &shop[i].spawn);
	}
}