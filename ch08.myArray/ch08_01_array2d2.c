#include <stdio.h>

int main(void)
{
	int arr2d[3][4] = {0};
	int arr1d[12] = {0};

	int row_count = sizeof(arr2d) / sizeof(arr2d[0]);       // 행 개수
	int col_count = sizeof(arr2d[0]) / sizeof(arr2d[0][0]); // 열 개수

	// 2차원 배열에 값 채우기
	int value = 1;
	for(int r = 0; r < row_count; ++r)
	{
		for(int c = 0; c < col_count; ++c)
		{
			arr2d[r][c] = ++value;
		}
	}

	// 2차원 배열 → 1차원 배열
	for(int r = 0; r < row_count; ++r)
	{
		for(int c = 0; c < col_count; ++c)
		{
			int index = r * col_count + c;
			arr1d[index] = arr2d[r][c];
		}
	}

	printf("1차원 배열 변환 결과:\n");
	for(int i = 0; i < row_count * col_count; ++i)
	{
		printf("%d ", arr1d[i]);	// 1차원 배열 출력
	}
	printf("\n\n");

	// 1차원 배열 → 또 다른 2차원 배열로 변경
	int arr2d_other[4][3] = {0};
	// 행/열 개수 다시 계산
	row_count = sizeof(arr2d_other) / sizeof(arr2d_other[0]);       // 행 개수
	col_count = sizeof(arr2d_other[0]) / sizeof(arr2d_other[0][0]); // 열 개수

	for(int i = 0; i < row_count * col_count; ++i)
	{
		int r = i / col_count; // 행 인덱스 = 1차원 인덱스 / 열 개수
		int c = i % col_count; // 열 인덱스 = 1차원 인덱스 % 열 개수
		arr2d_other[r][c] = arr1d[i];
	}

	//또 다른 2차원 배열로 변경된 내용 출력
	printf("다른 2차원 배열:\n");
	for(int r = 0; r < row_count; ++r)
	{
		for(int c = 0; c < col_count; ++c)
		{
			printf("%d ", arr2d_other[r][c]);
		}
		printf("\n");
	}

	return 0;
}
