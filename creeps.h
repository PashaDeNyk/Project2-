#pragma once
#include<iostream>
#include"structs.h"

void DestructCreeps(int i, Creep* creeps, Score& score, Textures* tex,healthPlayer& player);

void setCreep(int& max_count_creeps, Creep* creeps);

void SetWayCreeps(int& x);

void ClickCreep(int i, int mouse_x, int mouse_y, bool& mousebtdown, Creep* creeps, ClickUp& clickUp);

void HealthCreep(int i, Creep* creeps);

void AnimationCreeps(int& curpos, int i,Creep* creeps);

void ClickCreep(int i, int mouse_x, int mouse_y, bool& mousebtdown, Creep* creeps, ClickUp& clickUp);

void DrawCreeps(int& curpos, int mouse_x, int mouse_y, bool& mousebtdown, int& max_count_creeps, Creep* creeps, ClickUp& clickUp, Textures& tex, Score& score, healthPlayer& player);