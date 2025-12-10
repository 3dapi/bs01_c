#include <stdio.h>

int main(void)
{
	int arr[10] = {9, 4, 7, 1, 5, 10, 2, 7, 6, 4};
	int arr_count = sizeof(arr) / sizeof(arr[0]);

	// 정렬 전 출력
	printf("정렬 전: ");
	for(int i = 0; i < arr_count; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	// 삽입 정렬
	for(int i = 1; i < arr_count; ++i)
	{
		int key = arr[i];     // 새로 삽입할 값
		int j = i - 1;

		// key보다 큰 값들을 한 칸씩 오른쪽으로 이동
		for( ;0 <= j && key < arr[j]; --j)
		{
			arr[j + 1] = arr[j];
		}

		// 비어 있는 위치에 key 삽입
		arr[j + 1] = key;
	}

	// 정렬 후 출력
	printf("정렬 후: ");
	for(int i = 0; i < arr_count; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
