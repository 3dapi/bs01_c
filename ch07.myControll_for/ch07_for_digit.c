#include <stdio.h>

int main(void)
{
	int n = 12345678;   // 상황에 따라 주어진 숫자
	int digit = 0;      // 자릿수 저장 변수

	for(; n > 0; n /= 10)       // 초기식 생략, n을 계속 나누면서 감소
	{
		printf("%d ", n % 10);   // 가장 뒤 자릿수 출력
		++digit;                 // 자릿수 증가
	}

	printf("\nTotal digits: %d\n", digit);  // 총 자릿수 출력
	return 0;
}
