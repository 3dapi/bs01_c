#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand((unsigned int)time(NULL));

	int arr[3][4] = {0};   // 3행 4열 배열 초기화
	int row_count = sizeof(arr) / sizeof(arr[0]);
	int col_count = sizeof(arr[0]) / sizeof(arr[0][0]);

	for(int r = 0; r < row_count; ++r)
	{
		for(int c = 0; c < col_count; ++c)
		{
			arr[r][c] = -50 + rand() % (100 + 1); // 배열에 난수 저장([-50,50])
		}
	}

	int max = arr[0][0];
	int min = arr[0][0];
	int positive = 0, negative = 0;
	int even = 0, odd = 0;

	// 모든 원소 순회
	for(int r = 0; r < row_count; ++r)
	{
		for(int c = 0; c < col_count; ++c)
		{
			int value = arr[r][c];

			if(value > max)
				max = value;                      // 최대값

			if(value < min)
				min = value;                      // 최소값

			// 양수/음수
			if(value > 0)
				++positive;
			else if(value < 0)
				++negative;

			// 짝수/홀수
			(value % 2 == 0)? ++even: ++odd;
		}
	}

	// 결과 출력
	printf("최대값: %d\n", max);
	printf("최소값: %d\n", min);
	printf("양수 개수: %d, 음수 개수: %d\n", positive, negative);
	printf("짝수 개수: %d, 홀수 개수: %d\n", even, odd);

	return 0;
}