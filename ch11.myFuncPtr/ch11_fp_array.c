#include <stdio.h>

int Add(int a, int b) { return a + b; }
int Sub(int a, int b) { return a - b; }
int Mul(int a, int b) { return a * b; }
int Div(int a, int b)
{
	if(b == 0) {
		printf("0으로 나눌 수 없습니다.\n");
		return 0;
	}
	return a / b;
}

int main(void)
{
	int a = 20;
	int b = 10;
	int choice;

	typedef int(*OP)(int, int);

	// 0: Add, 1: Sub, 2: Mul, 3: Div
	int(*ops[])(int, int) = {Add, Sub, Mul, Div};
	//OP ops[] = {Add, Sub, Mul, Div};

	printf("연산 선택 (0: +, 1: -, 2: *, 3: /) : ");
	scanf("%d", &choice);

	if(choice < 0 || choice > 3) {
		printf("잘못된 선택입니다.\n");
		return 0;
	}

	printf("결과: %d\n", ops[choice](a, b));
	return 0;
}