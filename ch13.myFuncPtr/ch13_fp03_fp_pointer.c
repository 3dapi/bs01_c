#include <stdio.h>

int Add(int a, int b) { return a + b; }
int Mul(int a, int b) { return a * b; }

int main(void)
{
	int (*fp)(int, int);

	fp = Add;
	printf("Add 결과: %d\n", fp(10, 20));

	fp = Mul;
	printf("Mul 결과: %d\n", fp(10, 20));

	return 0;
}