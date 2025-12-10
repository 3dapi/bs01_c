#include <stdio.h>

int main(void)
{
	//  0~1000까지 정수 중 7의 배수 합계 구하기
	int sumSeven = 0;
	// for 문에서 사용한 int i를 while에서만 접근하도록 블록으로 감쌈
	{
		int i = 1;
		while(i <= 1000)   // 홀수만 순차적으로 증가
		{
			sumSeven += i;
			// 증감식	
			i += 7;  // 7씩 증가 → 7의 배수만 처리
		}
	}
	printf("1~1000까지  7의 배수 합: %d\n", sumSeven);


	int n = 12345678;   // 상황에 따라 주어진 숫자
	int digit = 0;      // 자릿수 저장 변수
	while(n > 0)
	{
		printf("%d ", n % 10);   // 가장 뒤 자릿수 출력
		++digit;                 // 자릿수 증가
		n /= 10;                 // 증감식	
	}
	printf("\nTotal digits: %d\n", digit);  // 총 자릿수 출력


	unsigned int imageSize = 2361;  // 기준 값
	unsigned int p = 1;             // 2의 승수를 저장할 변수
	while(p < imageSize)
	{
		p <<= 1;                    // p = p * 2 와 동일
	}
	printf("다음 2의 승수: %u --> %u\n", imageSize, p);


	printf(" 구구단 프로그램 \n");
	{
		int table = 2;
		while(table <= 9)                       // 바깥 반복문: 단(table)
		{
			printf("%d 단\n", table);           // 각 단 출력
			{
				int num = 2;
				while(num <= 9)                 // 안쪽 반복문: 곱하는 수(num)
				{
					int multi = table * num;    // 곱하기 결과
					printf("%d x %d = %d\n", table, num, multi);
					++num;
				}
			}
			printf("\n");                       // 각 단 출력 후 줄 구분
			++table;
		}
	}

	return 0;
}