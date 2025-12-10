#include <stdio.h>

int main(void)
{
	int arr2d[3][4] = { {1, 2, 3, 4}, {}, {5, 6},};
	

	int arr[2][3][4] = {0};

	int layer_count = sizeof(arr) / sizeof(arr[0]);
	int row_count   = sizeof(arr[0]) / sizeof(arr[0][0]);
	int col_count   = sizeof(arr[0][0]) / sizeof(arr[0][0][0]);

	for(int l = 0; l < layer_count; ++l)
	{
		for(int r = 0; r < row_count; ++r)
		{
			for(int c = 0; c < col_count; ++c)
			{
				arr[l][r][c] = (l * 100) + (r * 10) + c; // 값을 순서대로 채움.
			}
		}
	}

	for(int l = 0; l < layer_count; ++l)
	{
		printf("Layer %d:\n", l);
		for(int r = 0; r < row_count; ++r)
		{
			for(int c = 0; c < col_count; ++c)
			{
				printf("%3d ", arr[l][r][c]);    // 값 출력
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}