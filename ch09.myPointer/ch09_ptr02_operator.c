#include <stdio.h>

int main(void)
{
	int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	6[arr];	// arr[6]와 동일한 표현

	int* ptr = arr;	// 배열 주소 저장

	for(int i=0; i<9; ++i)
	{
		printf("arr[%d] = %d, *(arr+%d) =%d,  *(ptr+%d) = %d\n"
			, i, i[arr], i, *(arr+i), i, *(ptr+i));
		// arr[i] 대신 i[arr]로 써도 되지만 비추천이다.
	}

	return 0;
}
