#include<iostream>

#include"structs.h"


//���������� � �������� ����
void SaveBin(Tower* towers,Score& score)
{
	FILE* f;
	if (fopen_s(&f, "save.bin", "wb") != 0)
	{
		printf("Couldn't open file save.bin!\n");
		exit(1);
	}
	fwrite(&score.point,sizeof(int),1,f);
	for (int i = 0; i < 4; i++)
	{
		fwrite(&towers[i].index, sizeof(int), 1, f);
	}
	//fwrite(&score,sizeof(int),1,f)
	fclose(f);
}

//�������� �� ��������� �����
void LoadBin(Tower* towers,Score& score)
{
	FILE* f;
	if (fopen_s(&f, "save.bin", "rb") != 0)
	{
		printf("Couldn't open file save.bin!\n");
		exit(1);
	}
	fread(&score.point, sizeof(int), 1, f);
	for (int i = 0; i < 4; i++)
	{
		fread(&towers[i].index, sizeof(int), 1, f);
	}
	//fread(&score,sizeof(int),1,f)
	fclose(f);
}