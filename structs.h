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
	SDL_Texture* towerUp;
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
	bool score;
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
	int index;
	SDL_Texture* tex;
	SDL_Rect anim;
	SDL_Rect spawn;
	int lock = -1;
	int dist;
	int damage;
	int typedamage;
	int level=1;
	int range = 300;
	bool active = false;
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
	int point;
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
	SDL_Texture* tex;
	int level;
	int damage;
};