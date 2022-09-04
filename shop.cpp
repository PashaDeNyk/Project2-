#include<stdio.h>

#include"globalvar.h"
#include"structs.h"
#include"background.h"
#include"score.h"
#include"menu.h"


Shop shop[3];
Shopbg shopbg;
Places place;
Price price[3];

bool buy = false;
int buyType = 0;

void initShopbgTextures(const char filename[])
{
	shopbg.tex = loadTextureFromFile(filename, &shopbg.anim);
	shopbg.anim = { 406,236,150,34 };
	shopbg.spawn = { 0,500,1280,220 };
}

void initShopTextures(const char filename[], Tower* towers)
{
	for (int i = 0; i < 3; i++)
	{
		shop[i].tex = loadTextureFromFile(filename, &towers[i].anim);
	}
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
	if (buyType == 1)
	{
		towers[countTower].anim = { 0,0,150,105 };

		towers[countTower].rad = 200;
		towers[countTower].lock = 101;

		//Индекс башни для сохранения
		towers[countTower].index = towers[countTower].index + 1;

		//место спавна пули
		towers[countTower].bullet.x = towers[countTower].spawn.x + towers[countTower].spawn.w / 2;
		towers[countTower].bullet.y = towers[countTower].spawn.y + towers[countTower].spawn.h / 2;
		towers[countTower].bullet.w = 20;
		towers[countTower].bullet.h = 20;
		towers[countTower].shot_spawn = true;

		buyType = 0;
		countTower++;
	}
	else if (buyType == 2)
	{
		towers[countTower].anim = { 175,0,150,105 };

		towers[countTower].rad = 200;
		towers[countTower].lock = 101;

		towers[countTower].index = towers[countTower].index + 2;

		towers[countTower].bullet.x = towers[countTower].spawn.x + towers[countTower].spawn.w / 2;
		towers[countTower].bullet.y = towers[countTower].spawn.y + towers[countTower].spawn.h / 2;
		towers[countTower].bullet.w = 20;
		towers[countTower].bullet.h = 20;
		towers[countTower].shot_spawn = true;

		buyType = 0;
		countTower++;
	}
	else if (buyType == 3)
	{
		towers[countTower].anim = { 355,0,150,105 };

		towers[countTower].rad = 200;
		towers[countTower].lock = 101;

		towers[countTower].index = towers[countTower].index + 3;

		towers[countTower].bullet.x = towers[countTower].spawn.x + towers[countTower].spawn.w / 2;
		towers[countTower].bullet.y = towers[countTower].spawn.y + towers[countTower].spawn.h / 2;
		towers[countTower].bullet.w = 20;
		towers[countTower].bullet.h = 20;
		towers[countTower].shot_spawn = true;

		buyType = 0;
		countTower++;
	}

}

//Определение места постройки башни
void buildTower(int mouse_x, int mouse_y, int& countTower, bool& mousebtdown, bool& checkSpawn1, bool& checkSpawn2, bool& checkSpawn3, bool& checkSpawn4, Tower* towers, bool& load, Upgrade* up)
{
	if (buy == true)
	{

		//Левая башня сверху
		if (checkSpawn1 == false and mousebtdown == true and mouse_x >= place.p1.x and mouse_x <= place.p1.x + place.p1.w and mouse_y >= place.p1.y and mouse_y <= place.p1.y + place.p1.h)
		{
			checkSpawn1 = true;

			mousebtdown = false;
			buy = false;

			towers[countTower].spawn = { 340,183,150,105 };
			up[countTower].drawRect = { 500,265,20,20 };
			up[countTower].drawRect_level = { 500,235,50,25 };

			towers[countTower].index = 10;

			setTypeTower(buyType, countTower, towers);
		}

		//Правая башня сверху
		else if (checkSpawn2 == false and mousebtdown == true and mouse_x >= place.p2.x and mouse_x <= place.p2.x + place.p2.w and mouse_y >= place.p2.y and mouse_y <= place.p2.y + place.p2.h)
		{
			checkSpawn2 = true;

			mousebtdown = false;
			buy = false;

			towers[countTower].spawn = { 923,180,150,105 };
			up[countTower].drawRect = { 1083,265,20,20 };
			up[countTower].drawRect_level = { 1083,235,50,25 };
			towers[countTower].index = 20;

			setTypeTower(buyType, countTower, towers);
		}

		else if (checkSpawn3 == false and mousebtdown == true and mouse_x >= place.p3.x and mouse_x <= place.p3.x + place.p3.w and mouse_y >= place.p3.y and mouse_y <= place.p3.y + place.p3.h)
		{
			checkSpawn3 = true;

			mousebtdown = false;
			buy = false;

			towers[countTower].spawn = { 128,363,150,105 };
			up[countTower].drawRect = { 288,448,20,20 };
			up[countTower].drawRect_level = { 288,418,50,25 };
			//initUpgrade(countTower);
			towers[countTower].index = 30;

			setTypeTower(buyType, countTower, towers);
		}

		else if (checkSpawn4 == false and mousebtdown == true and mouse_x >= place.p4.x and mouse_x <= place.p4.x + place.p4.w and mouse_y >= place.p4.y and mouse_y <= place.p4.y + place.p4.h)
		{
			checkSpawn4 = true;

			mousebtdown = false;
			buy = false;

			towers[countTower].spawn = { 594,363,150,105 };
			up[countTower].drawRect = { 754,448,20,20 };
			up[countTower].drawRect_level = { 754,418,50,25 };

			towers[countTower].index = 40;

			setTypeTower(buyType, countTower, towers);
		}

		//Отмена покупки башни(не работает)
		//if (rightbtdown == true)
		//{
		// buyType = 0;
		// rightbtdown = false;
		// buy = false;
		//}
	}

	if (load)
	{
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
				towers[i].spawn = { 340,183,150,105 };
				checkSpawn1 = true;
				break;
			}
			case 2:
			{
				towers[i].spawn = { 923,180,150,105 };
				checkSpawn2 = true;
				break;
			}
			case 3:
			{
				towers[i].spawn = { 128,363,150,105 };
				checkSpawn3 = true;
				break;
			}
			case 4:
			{
				towers[i].spawn = { 594,363,150,105 };
				checkSpawn4 = true;
				break;
			}
			break;
			}

			switch (typeT)
			{
			case 1:
			{
				buyType = 1;
				break;
			}
			case 2:
			{
				buyType = 2;
				break;
			}
			case 3:
			{
				buyType = 3;
				break;
			}
			break;
			}
			setTypeTower(buyType, i, towers);
		}
		load = false;
	}

}

void buyingClickTower(int mouse_x, int mouse_y, bool& mousebtdown, bool& scoreBuying)
{
	if (mousebtdown == true and mouse_x >= shop[0].spawn.x and mouse_x <= shop[0].spawn.x + shop[0].spawn.w and mouse_y >= shop[0].spawn.y and mouse_y <= shop[0].spawn.y + shop[0].spawn.h)
	{
		ScoreCheck(100, scoreBuying);
		if (scoreBuying)
		{
			buy = true;
			buyType = 1;
			ScoreUpdate(-100);
			mousebtdown = false;
		}
		scoreBuying = false;
	}
	else
		if (mousebtdown == true and mouse_x >= shop[1].spawn.x and mouse_x <= shop[1].spawn.x + shop[1].spawn.w and mouse_y >= shop[1].spawn.y and mouse_y <= shop[1].spawn.y + shop[1].spawn.h)
		{
			ScoreCheck(200, scoreBuying);
			if (scoreBuying)
			{
				buy = true;
				buyType = 2;
				ScoreUpdate(-200);
				mousebtdown = false;
			}
			scoreBuying = false;
		}
		else
			if (mousebtdown == true and mouse_x >= shop[2].spawn.x and mouse_x <= shop[2].spawn.x + shop[2].spawn.w and mouse_y >= shop[2].spawn.y and mouse_y <= shop[2].spawn.y + shop[2].spawn.h)
			{
				ScoreCheck(300, scoreBuying);
				if (scoreBuying)
				{
					buy = true;
					buyType = 3;
					ScoreUpdate(-300);
					mousebtdown = false;
				}
				scoreBuying = false;
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

void DrawShop()
{
	SDL_RenderCopy(ren, shopbg.tex, &shopbg.anim, &shopbg.spawn);
	SetShop();
	DrawPrice();
	for (int i = 0; i < 3; i++)
	{
		SDL_RenderCopy(ren, shop[i].tex, &shop[i].anim, &shop[i].spawn);
	}
}