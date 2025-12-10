#include <stdio.h>

int main(void)
{
	int a;
	a = (1,2,3);   // 1, 2를 평가한 후 마지막 값 3을 a에 대입

	int x = 0, y = 0;
	x = (y = 10, y + 5);   // y = 10 실행 → y + 5 실행 → 결과 15가 x에 저장

	printf("a: %d\n", a); // 출력: a: 3
	printf("x: %d\n", x); // 출력: x: 15

	for(int i=0; i<100; ++i)
		printf("%d ", (i % 10, i)); // i % 10은 평가되지만 무시되고 i가 출력됨

	return 0;

}