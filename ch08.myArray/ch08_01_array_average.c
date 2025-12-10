#include <stdio.h>

int main(void)
{
	int arr[100] = {0};   // 배열 원소를 0으로 초기화
	int arr_number = sizeof(arr) / sizeof(arr[0]);

	// 배열에 1부터 100까지 값 저장
	for(int i = 0; i < arr_number; ++i)
	{
		arr[i] = i + 1;
	}

	// 합계 계산
	int sum = 0;
	for(int i = 0; i < arr_number; ++i)
	{
		sum += arr[i];
	}

	// 평균 계산	및 출력
	double average = (double)sum / arr_number;
	printf("평균: %.4f\n", average);

	return 0;
}
