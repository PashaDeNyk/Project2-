#pragma once
#include<iostream>
#include"structs.h"

void DeInit(int error);

void Init();

void initCreepTextures(const char filename[], Textures& tex);

void initTowerTextures(const char filename[], Textures& tex);

void DestroyTexture(SDL_Texture* name_texture, int k);