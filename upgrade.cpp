#include<stdio.h>
#include"structs.h"
#include"globalvar.h"
#include"menu.h"

void initUpgrade(int i,Upgrade* up)
{
	up[i].textures = loadFont("lvl 1","");
}

void DrawLevelUpgrade(Upgrade* up)
{
	for (int i = 0; i < 4; i++)
	{
		SDL_RenderCopy(ren,up[i].texture.tex);
	}
}