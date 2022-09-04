#pragma once
#include"structs.h"

void initBulletTextures(const char filename[], Bullet* shot);

int Distance(Creep creep, Tower tower);

void WayBullet(Creep& creep, Bullet& shot, Tower& tower);

void CheckDistance(int& timerBullet, int max_count_creeps, Creep* creeps, Tower* towers, Bullet* shot);