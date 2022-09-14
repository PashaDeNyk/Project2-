#pragma once
#include"structs.h"

void initBulletTextures(const char filename[], Bull& shot);

int Distance(Creep creep, Tower tower);

void WayBullet(Creep& creep, Tower& tower);

void CheckDistance(int& timerBullet, int max_count_creeps, Creep* creeps, Tower* towers);