#include <stdio.h>

int main(void)
{
	int  arr[] = {     1,  2,  3,  4
					,  5,  6,  7,  8
					,  9, 10, 11, 12
					, 13, 14};

	// 배열을 4개씩 묶어서 보는 배열 포인터 선언
	int (*ptr_arr)[4] = NULL;

	// 배열 전체의 주소(&arr)를 배열 포인터에 저장
	ptr_arr = &arr;

	for(int i=0; i<4; ++i)
	{
		printf("ptr_arr %d: [%2d %2d %2d %2d]\n"
				, i+1, *(ptr_arr[i]+0), *(ptr_arr[i]+1), *(ptr_arr[i]+2), *(ptr_arr[i]+3));
	}

	return 0;
}
