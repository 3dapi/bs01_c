#include <stdio.h>
#include <string.h>
#include "AppData.h"

typedef struct Data
{
	int gameData;
}Data;

static Data g_Data;

// 게임 데이터 초기화.
int InitData(void)
{
	printf("InitData\n");
	return 0;
}

// 게임 데이터 저장.
int SaveData(void)
{
	printf("SaveData\n");
	return 0;
}

// 게임 데이터 해제.
int DestroyData(void)
{
	printf("DestroyData\n");
	return 0;
}
