#include<iostream>
#include"globalvar.h"
#include"structs.h"
#include"menu.h"


void ScoreCheck(int point,bool& scoreBuying,Score& score)
{
	if (score.point >= point)
	{
		scoreBuying = true;
	}
}

void ScoreUpdate(int point, Score& score)
{
	score.point+=point;
	if (score.textures.tex)
		SDL_DestroyTexture(score.textures.tex);
	char message[100];
	sprintf_s(message, "Score %i", score.point);

	score.textures = loadFont(message, "fonts\\Chava-Regular.ttf", { 0, 0, 200, 255 }, 25);
	
}

void initScore(Score& score)
{
	score.drawRect = { 0,0,200,35 };
	score.point = 100;
	ScoreUpdate(score.point,score);
}

void DrawScore(Score& score)
{
	SDL_RenderCopy(ren, score.textures.tex, NULL, &score.drawRect);
}

