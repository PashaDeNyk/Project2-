#pragma once
#include<iostream>

void ScoreCheck(int point, bool& scoreBuying, Score& score);

void initScore(Score& score);

void ScoreUpdate( int point, Score& score);

void DrawScore(Score& score);
