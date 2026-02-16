#include <stdio.h>
#include <string.h>
#include "GameLobby.h"

// GameLobby 초기화.
int InitGameLobby(void)
{
	printf("InitGameLobby\n");
	return 0;
}

// GameLobby 업데이트.
int UpdateGameLobby(void)
{
	return 0;
}

// GameLobby 해제.
int DestroyGameLobby(void)
{
	printf("DestroyGameLobby\n");
	return 0;
}

void MenuGameLobby(void)
{
	printf("\n");
	printf("========================================================\n");
	printf("	오  락  실\n");
	printf("========================================================\n");
	printf("\n");
	printf("	1. 홀짝 게임\n");
	printf("	2. Up/Down 게임\n");
	printf("	3. 가위바위보\n");
	printf("\n");
	printf("	Q. 종료\n");
	printf("\n");
	printf("--------------------------------------------------------\n");
}
