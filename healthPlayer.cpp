#include<iostream>
#include"globalvar.h"
#include"structs.h"
#include"menu.h"

void initHealth(healthPlayer& player)
{
	player.drawRect = { 1160,465,110,35 };
	player.textures = loadFont("Health 10", "fonts\\Chava-Regular.ttf", { 0,0,200,255 }, 25);
}

void UpdateHealth(healthPlayer& player)
{
	if (player.textures.tex)
		SDL_DestroyTexture(player.textures.tex);
	char message[100];
	sprintf_s(message, "Health %i", player.health);

	player.textures = loadFont(message, "fonts\\Chava-Regular.ttf", { 0, 0, 200, 255 }, 25);
}

void DamagePlayer(int damage, healthPlayer& player)
{
	if (player.health >= damage)
	{
		player.health -= damage;
		UpdateHealth(player);
	}
	else if (player.health == 0)
		SDL_Quit();
}

void DrawHealth(healthPlayer& player)
{
	SDL_RenderCopy(ren, player.textures.tex, NULL, &player.drawRect);
}