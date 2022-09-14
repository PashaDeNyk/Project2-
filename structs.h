#pragma once
#include<iostream>
#include<SDL.h>

struct Texture
{
	SDL_Texture* tex = NULL;
	int          w;
	int          h;
	SDL_Rect     dstrect;
};

struct Textures
{
	SDL_Texture* background;
	SDL_Texture* creep;
	SDL_Texture* tower;
	SDL_Texture* shobg;
};

struct Menu
{
	Texture textures;
	SDL_Rect drawRect;
};

struct Background
{
	SDL_Texture* tex;
	SDL_Rect rect;
};

struct Creep
{
	SDL_Rect anim;		 int xAnim, yAnim;
	SDL_Rect damageRect;  SDL_Rect healthRect; int health;
	int xWay, yWay;
	bool active;
	bool inZone;
	bool score;

	int cher_way;
	bool cher_bool;
};

struct Bullet
{
	SDL_Texture* tex;
	SDL_Rect anim;
	SDL_Rect bullet;
	float x, y;
	bool spawn;
};

struct Bull
{
	SDL_Texture* tex;
	SDL_Rect anim;
	SDL_Rect rect = {0,0,10,10};
	float x, y;
};

struct Tower
{
	int index;//for save and load

	SDL_Texture* tex;
	SDL_Rect anim;
	SDL_Rect spawn;

	int lock = -1;//lock in enemy
	int dist;//distance to the creep
	int damage;//damage bullet
	int level;//level tower(up damage)
	int range = 300;

	Bull bullet;
};

struct Places
{
	SDL_Rect p1 = { 340,183,150,100 };
	SDL_Rect p2 = { 920,183,150,100 };
	SDL_Rect p3 = { 128,363,150,100 };
	SDL_Rect p4 = { 594,363,150,100 };
};

struct Shop
{
	SDL_Rect spawn;
	SDL_Rect anim;
};

struct Shopbg
{
	SDL_Texture* tex;
	SDL_Rect anim;
	SDL_Rect spawn;
};

struct Score
{
	Texture textures;
	SDL_Rect drawRect;
	int point = 100;
};

struct Price
{
	Texture textures;
	SDL_Rect drawRect;
	int cost;
};

struct Upgrade
{
	Texture textures;
	SDL_Rect button;
	SDL_Rect drawRect;
};

struct Info
{
	Texture textures;
	SDL_Rect drawRect;
};

struct ClickUp
{
	Texture textures;
	SDL_Rect button;
	SDL_Rect drawRect;
	SDL_Rect lvlRect;
	int level;
	int damage;
};