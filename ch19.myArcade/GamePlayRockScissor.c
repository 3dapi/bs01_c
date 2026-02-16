#include <stdio.h>
#include <string.h>
#include "GamePlayRockScissor.h"

// GamePlayRockScissor 초기화.
int InitGamePlayRockScissor(void)
{
	printf("InitGamePlayRockScissor\n");
	return 0;
}

// GamePlayRockScissor 업데이트.
int UpdateGamePlayRockScissor(void)
{
	printf("UpdateGamePlayRockScissor\n");
	return 0;
}

// GamePlayRockScissor 해제.
int DestroyGamePlayRockScissor(void)
{
	printf("DestroyGamePlayRockScissor\n");
	return 0;
}

void MenuGamePlayRockScissor(void)
{
	printf("\n");
	printf("========================================================\n");
	printf("[가위바위보 게임]  (5판 3선승제)\n");
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
