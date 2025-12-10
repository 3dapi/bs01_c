#include <stdio.h>

void ModifyArray(int arr[], int size)
{
	for(int i = 0; i < size; ++i)
	{
		arr[i] = arr[i] * 2;   // 모든 값을 2배로 변경
	}
}

int main(void)
{
	int data[5] = {1, 2, 3, 4, 5};

	printf("함수 호출 전: ");
	for(int i = 0; i < 5; ++i)
		printf("%d ", data[i]);
	printf("\n");

	ModifyArray(data, 5); // 배열의 주소가 전달된다.

	printf("함수 호출 후: ");
	for(int i = 0; i < 5; ++i)
		printf("%d ", data[i]);
	printf("\n");

	return 0;
}

