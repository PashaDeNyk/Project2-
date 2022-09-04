#include<stdio.h>
#include"structs.h"
#include"globalvar.h"
#include"background.h"

Bullet shot[4];

void initBulletTextures(const char filename[], Bullet* shot)
{
	for (int i = 0; i < 4; i++)
	{
		shot[i].tex = loadTextureFromFile(filename, &shot[i].anim);
	}
}

int Distance(Creep creep, Tower tower)
{
	return sqrt((creep.xWay - tower.spawn.x) * (creep.xWay - tower.spawn.x) + (creep.yWay - tower.spawn.y) * (creep.yWay - tower.spawn.y));
}

//Отрисовка пули если она активна, если нет то она пропадает за задником
void WayBullet(Creep& creep,Bullet& shot,Tower& tower)
{
	float angle = atan2(creep.yWay - tower.spawn.y, creep.xWay - tower.spawn.x);
	//if (shot.bullet.x != creep.xWay)
	shot.bullet.x += (int)cos(angle) * 2;
	//if (shot.bullet.y != creep.yWay)
	shot.bullet.y += (int)sin(angle) * 2;
	//if (Distance(creep, tower) >= tower.dist)
	if (shot.bullet.x >= creep.xWay and shot.bullet.x <= creep.xWay + 42 and shot.bullet.y >= creep.yWay and shot.bullet.y <= creep.yWay + 84)
	{
		//Отнимаем хп у крипа
		shot.bullet.x = (tower.spawn.x + tower.spawn.w / 2);
		shot.bullet.y = (tower.spawn.y + tower.spawn.h / 2);
		creep.health -= 1;
		shot.lock = -1;
	}
	//Отрисовываем
	SDL_RenderCopy(ren, tower.shot_tex, NULL, &tower.bullet);
}

void CheckDistance(int& timerBullet, int max_count_creeps, Creep* creeps, Tower* towers,Bullet* shot)
{
	for (int k = 0; k < 4; k++)
	{
		for (int i = 0; i < max_count_creeps; i++)
		{
			if (creeps[i].active)
			{
				shot[k].dist = Distance(creeps[i], towers[k]);
				//printf("%i", towers[k].dist);
				//system("cls");
				if (shot[k].dist <= shot[k].rad and shot[k].lock == -1)
				{

					shot[k].lock = i;
					timerBullet++;
					//WayBullet(creeps[towers[k].lock], towers[k]);
				}
				if (shot[k].lock != -1)
				{
					WayBullet(creeps[shot[k].lock], shot[k],towers[k]);
				}
			}
		}
	}
}
