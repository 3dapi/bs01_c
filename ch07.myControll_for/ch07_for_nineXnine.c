#include <stdio.h>

int main(void)
{
	printf(" 구구단 프로그램 \n");
	for(int table = 2; table <= 9; ++table)     // 바깥 반복문: 단(table)
	{
		printf("%d 단\n", table);               // 각 단 출력
		for(int num = 2; num <= 9; ++num)       // 안쪽 반복문: 곱하는 수(num)
		{
			int multi = table * num;            // 곱하기 결과
			printf("%d x %d = %d\n", table, num, multi);
		}
		printf("\n");                           // 각 단 출력 후 줄 구분
	}

	return 0;
}
