#pragma once
#include "structs.h"

Texture loadFont(const char text[], const char fontname[], SDL_Color color, int hgt);

void MenuDestroy();

void getInfo();

void MenuClick(int mouse_x, int mouse_y, bool& startgame, bool& startapp, bool& bgcreeps, bool& mousebtdown,bool& isRunning, bool& startInfo);

void drawMenu(int i, int mouse_x, int mouse_y, bool& startgame, bool& startapp, bool& bgcreeps, bool& mousebtdown);

//void GameOver();