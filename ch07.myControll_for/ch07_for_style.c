#include <stdio.h>

int main(void)
{
	int jobCount = 4;    // 실행해야 할 작업 개수(상황에 따라 결정됨)
	int playCount = 0;   // 반복문 앞에서 선언 및 초기화

	// 초기식 생략
	for(; playCount < jobCount; ++playCount)
	{
		// 어떤 작업 수행
	}
	printf("반복 종료 후 playCount = %d 회 실행되었습니다.\n", playCount);

	printf("----------------------------------------------------\n");

	for(int i = 0; i < 10; )
	{
		printf("%d\n", i);

		i += 2;    // 증감식 대신 반복문 내부에서 증가
	}

	printf("----------------------------------------------------\n");
	int i = 0;

	for(; i < 10; )    // 초기식 없음, 증감식 없음
	{
		printf("%d\n", i);

		++i;            // 반복문 내부에서 증가
	}

	printf("----------------------------------------------------\n");

	for(;;)
	{
		// 반복 실행할 문장
		if(1/* 특정 조건 */)
			break;     // 직접 탈출
	}

	return 0;
}

