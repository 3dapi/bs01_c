#include <stdio.h>
#include <string.h>
#include "GameResult.h"

// GameResult 초기화.
int InitGameResult(void)
{
	printf("InitGameResult\n");
	return 0;
}

// GameResult 업데이트.
int UpdateGameResult(void)
{
	printf("UpdateGameResult\n");
	return 0;
}

// GameResult 해제.
int DestroyGameResult(void)
{
	printf("DestroyGameResult\n");
	return 0;
}

void MenuGameResult(void)
{
	printf("\n");
	printf("========================================================\n");
	printf("[게임 결과]\n");
	printf("========================================================\n");
	printf("\n");
	printf("게임: UpDown\n");
	printf("결과: WIN\n");
	printf("총 시도: 4 회\n");
	printf("\n");
	printf("--------------------------------------------------------\n");
	printf("[최근 기록]\n");
	printf("2026-02-16  17:32:10   UpDown   3:2   WIN\n");
	printf("2026-02-16  17:18:02   홀짝      3:1   WIN\n");
}