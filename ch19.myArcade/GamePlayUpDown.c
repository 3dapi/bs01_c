#include <stdio.h>
#include <string.h>
#include "GamePlayUpDown.h"

// GamePlayUpDown 초기화.
int InitGamePlayUpDown(void)
{
	printf("InitGamePlayUpDown\n");
	return 0;
}

// GamePlayUpDown 업데이트.
int UpdateGamePlayUpDown(void)
{
	printf("UpdateGamePlayUpDown\n");
	return 0;
}

// GamePlayUpDown 해제.
int DestroyGamePlayUpDown(void)
{
	printf("DestroyGamePlayUpDown\n");
	return 0;
}

void MenuGamePlayUpDown(void)
{
	printf("\n");
	printf("========================================================\n");
	printf("[Up/Dwon 게임]  (5판 3선승제)\n");
	printf("========================================================\n");
	printf("\n");
	printf("진행: 2 / 5 판\n");
	printf("승패: 내 승 1  |  컴 승 0\n");
	printf("최근 결과: WIN\n");
	printf("\n");
	printf("--------------------------------------------------------\n");
	printf("메뉴: [R] 재시작[Q] 게임 종료(로비)\n");
	printf("\n");
	printf("입력 안내:\n");
	printf("- 게임 규칙 입력\n");
	printf("- 치트키: (W)즉시 승리   (L) 즉시 패배\n");
	printf("--------------------------------------------------------\n");
}