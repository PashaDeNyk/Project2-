#include<iostream>
#include"globalvar.h"
#include"structs.h"
#include"menu.h"

Score score;

void ScoreCheck(int point,bool& scoreBuying)
{
	if (score.point >= point)
	{
		scoreBuying = true;
	}
}

void ScoreUpdate(int point)
{
	score.point+=point;
	if (score.textures.tex)
		SDL_DestroyTexture(score.textures.tex);
	char message[100];
	sprintf_s(message, "Score %i", score.point);

	score.textures = loadFont(message, "fonts\\Chava-Regular.ttf", { 0, 0, 200, 255 }, 25);
	
}

void initScore()
{
	score.drawRect = { 0,0,200,35 };
	score.point = 0;
	ScoreUpdate(score.point);
}

void DrawScore()
{
	SDL_RenderCopy(ren, score.textures.tex, NULL, &score.drawRect);
}

