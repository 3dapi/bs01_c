#include <stdio.h>

// 함수의 매개변수 정보 없음
void hasNotVoidFunc()
{
	printf("call hasNotVoidFunc()\n");
}

// 함수의 매개변수 없음
void hasVoidFunc(void)
{
	printf("call hasVoidFunc(void)\n");
}

int main(void)
{
    hasNotVoidFunc(1,2,4);	// warning 없음
    hasVoidFunc(1, 2, 4);	// warning 발생
    return 0;
}
