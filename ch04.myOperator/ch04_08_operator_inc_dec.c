#include <stdio.h>

int main(void)
{
	{
		int a = 5;
		int b = a++;
		printf("[a: %d], [b: %d]\n" , a, b);
		return 0;
	}

	{
		// 이렇게 전위, 후위 섞여있는 경우는 정의되지 않은 동작(UB)이 발생할 수 있다.
		int a = 5;
		int b = a++ + ++a + a++ + ++a + a++ + ++a;
		printf("[a: %d], [b: %d]\n", a, b);
	}

	{
		int a = 5;
		int b = a++, c = a++, d = a++, e = a++, f = a++, g = a++;

		printf("[a: %d], [b: %d], [c: %d], [d: %d], [e: %d], [f: %d], [g: %d]\n"
				, a, b, c, d, e, f, g);
	}
	return 0;

}