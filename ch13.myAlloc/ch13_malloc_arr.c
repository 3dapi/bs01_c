#include <stdio.h>
#include <stdlib.h>    // malloc, free

int main(void)
{
	const int count = 10;
	const int buf_size = sizeof(int) * count;

	int* ptr_arr = (int*)malloc(buf_size);
	if(!ptr_arr)
	{
		printf("malloc 실패\n");
		return 1;
	}

	// 연속된 메모리 공간에 값을 저장
	for(int i = 0; i < count; ++i)
		ptr_arr[i] = (i + 1) * 10;

	for(int i = 0; i < count; ++i)
		printf("ptr_arr[%d] = %d\n", i, ptr_arr[i]);

	free(ptr_arr);
	ptr_arr = NULL;   // 댕글링 포인터 방지

	return 0;
}
