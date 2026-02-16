#include <stdio.h>
#include <string.h>
#include "GamePlayOddEven.h"

// GamePlayOddEven 초기화.
int InitGamePlayOddEven(void)
{
	printf("InitGamePlayOddEven\n");
	return 0;
}

// GamePlayOddEven 업데이트.
int UpdateGamePlayOddEven(void)
{
	printf("UpdateGamePlayOddEven\n");
	return 0;
}

// GamePlayOddEven 해제.
int DestroyGamePlayOddEven(void)
{
	printf("DestroyGamePlayOddEven\n");
	return 0;
}

void MenuGamePlayOddEven(void)
{
	printf("\n");
	printf("========================================================\n");
	printf("[홀짝 게임]  (5판 3선승제)\n");
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
