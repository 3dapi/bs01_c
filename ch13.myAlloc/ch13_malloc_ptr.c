#include <stdio.h>
#include <stdlib.h>    // malloc, free
#include <string.h>    // memset

int main(void)
{
	const int buf_size = sizeof(int);

	// C언어는 casting을 안해도 문제가 없지만, C++에서는 malloc의 반환값이 void*이므로
	// 명시적으로 int*로 캐스팅해야 한다.
	// C에서는 이렇게 해도 된다.
	// int* ptr = malloc(buf_size);

	int* ptr = (int*)malloc(buf_size);
	if(!ptr) //if(NULL == ptr)
	{
		printf("malloc 실패\n");
		return 1;
	}
	// 동적 메모리는 초기화되지 않으므로 필요 시 초기화한다.
	memset(ptr, 0, buf_size);

	*ptr = 10;
	printf("*ptr = %d\n", *ptr);

	free(ptr);
	// 댕글링 포인터 방지: 이미 해제된 메모리를 다시 사용하지 않도록 NULL로 설정
	ptr = NULL;

	return 0;
}
