#include <stdio.h>

int main(void)
{
	int arr2d[3][4] = {
		{ 1,  2,  3,  4},
		{ 5,  6,  7,  8},
		{ 9, 10, 11, 12}
	};

	int result[4][3] = {0};
	int row_count = sizeof(arr2d) / sizeof(arr2d[0]);       // 행 개수
	int col_count = sizeof(arr2d[0]) / sizeof(arr2d[0][0]); // 열 개수 

	// 전치 (Transpose)
	for(int r = 0; r < row_count; ++r)
	{
		for(int c = 0; c < col_count; ++c)
		{
			result[c][r] = arr2d[r][c];
		}
	}

	printf("전치된 행렬:\n");
	for(int r = 0; r < col_count; ++r)
	{
		for(int c = 0; c < row_count; ++c)
		{
			printf("%2d ", result[r][c]);     // 전치된 행렬 출력
		}
		printf("\n");
	}

	return 0;
}
