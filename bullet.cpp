#include<stdio.h>
#include"structs.h"
#include"globalvar.h"
#include"background.h"
#include"score.h"
#include"healthPlayer.h"

void initBulletTextures(const char filename[], Bull& shot)
{
		shot.tex = loadTextureFromFile(filename, &shot.anim);
}

int Distance(Creep creep, Tower tower)
{
	return sqrt((creep.xWay - tower.spawn.x) * (creep.xWay - tower.spawn.x) + (creep.yWay - tower.spawn.y) * (creep.yWay - tower.spawn.y));
}

void WayBullet(Creep& creep, Tower& tower)
{
	float angle = atan2(creep.yWay + 21 - tower.bullet.y, creep.xWay + 42 - tower.bullet.x);

	tower.bullet.x += cos(angle);
	tower.bullet.y += sin(angle);

	tower.bullet.rect.x = (int)tower.bullet.x;
	tower.bullet.rect.y = (int)tower.bullet.y;

	if (creep.health <= 0)
		tower.lock = -1;

	if (tower.lock!=-1 and tower.bullet.x >= creep.xWay and tower.bullet.x <= creep.xWay + 42 and tower.bullet.y >= creep.yWay and tower.bullet.y <= creep.yWay + 84)
	{
		tower.bullet.x = (tower.spawn.x + tower.spawn.w / 2);
		tower.bullet.y = (tower.spawn.y + tower.spawn.w / 2);
		creep.health -= tower.damage;
	}

	SDL_RenderCopy(ren, tower.bullet.tex, NULL, &tower.bullet.rect);
}

void CheckDistance(int& timerBullet, int max_count_creeps, Creep* creeps, Tower* towers)
{
	for (int k = 0; k < 4; k++)
	{
		if (towers[k].index >= 0)
			for (int i = 0; i < max_count_creeps; i++)
			{
				if (creeps[i].active)
				{
					towers[k].dist = Distance(creeps[i], towers[k]);
					if (towers[k].dist <= towers[k].range and towers[k].lock == -1)
					{
						towers[k].lock = i;
						timerBullet++;
					}
					if (towers[k].lock != -1)
					{
						WayBullet(creeps[towers[k].lock], towers[k]);
					}
				}
			}
	}
}