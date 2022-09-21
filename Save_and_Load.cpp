#include<iostream>
#include"structs.h"

//Сохранение в бинарный файл
void SaveBin(Tower* towers, Score& score, healthPlayer& player, ClickUp& clickUp)
{
	FILE* f;
	if (fopen_s(&f, "save.bin", "wb") != 0)
	{
		printf("Couldn't open file save.bin!\n");
		exit(1);
	}
	fwrite(&score.point, sizeof(int), 1, f);
	for (int i = 0; i < 4; i++)
		fwrite(&towers[i].index, sizeof(int), 1, f);
	for (int i = 0; i < 4; i++)
		fwrite(&towers[i].level, sizeof(int), 1, f);
	fwrite(&player.health, sizeof(int), 1, f);
	fwrite(&clickUp.level, sizeof(int), 1, f);
	fclose(f);
}

//Загрузка из бинарного файла
void LoadBin(Tower* towers, Score& score,healthPlayer& player, ClickUp& clickUp)
{
	FILE* f;
	if (fopen_s(&f, "save.bin", "rb") != 0)
	{
		printf("Couldn't open file save.bin!\n");
		exit(1);
	}
	fread(&score.point, sizeof(int), 1, f);
	for (int i = 0; i < 4; i++)
		fread(&towers[i].index, sizeof(int), 1, f);
	for (int i = 0; i < 4; i++)
		fread(&towers[i].level, sizeof(int), 1, f);
	fread(&player.health, sizeof(int), 1, f);
	fread(&clickUp.level, sizeof(int), 1, f);
	fclose(f);
}