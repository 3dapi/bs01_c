#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int GetRandom(int min, int max);        // [min, max] 범위 random 값 생성 함수.

int main(void)
{
	srand((unsigned int)time(NULL));    // Random Seed 설정.

	int compValue = GetRandom(1, 10);   // 1~10 사이 random 값 얻기.
	int isEven = compValue % 2;         // 짝 또는 홀 으로 저장.

	printf("홀짝 게임을 진행합니다=================\n");
	printf("홀(1), 짝(0) 중 하나를 선택하세요: ");
	int playerValue = 0;                // 사용자 입력 값.
	scanf("%d", &playerValue);          // 사용자 입력 값 저장.

	// 정답 여부 확인 (같으면 승리)
	int isWin = (isEven == playerValue);

	// 삼항 조건 연산자로 결과 출력
	(isWin)
		? printf("승리!!! (%d)\n", compValue)
		: printf("패배 !!! (%d)\n", compValue);

	return 0;
}

int GetRandom(int min, int max)
{
	return min + rand() % (max - min + 1);
}