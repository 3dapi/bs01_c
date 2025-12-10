#include <stdio.h>

int main(void)
{
	int i = 0;
	// 초기식 또는 조건식에 실행 문이 있는 경우
	for(printf("초기식\n", i); i < 10; printf("증감식 값: %d\n", i), i += 2)
	{
	}

	// 초기식 변수를 다 넣는 경우
	for(int i=0, j=0, k=0, l=0, m=0, n=0; 0 ; ++i, ++j, ++k, ++l, ++m, ++n)
	{
	}

	// 중괄호가 생략된 경우
	int n=0;
	for(int i=1; i<10 ; ++i, n*i);

	// 중괄호가 생략된 경우
	for(int i=0; 0 ; ++i) printf("\n");

	// 중괄호가 있으나 한줄인 경우
	for(int i=0; 0 ; ++i) { printf("\n"); }

	return 0;
}

