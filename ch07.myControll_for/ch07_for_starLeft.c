#include <stdio.h>

int main(void)
{
	int maxStar = 4;                    // 최대 별 개수
	for(int i = 1; i <= maxStar; ++i)   // i는 줄(row)
	{
		for(int j = 1; j <= i; ++j)     // j는 각 줄의 별 개수(column)
		{
			printf("*");
		}
		printf("\n");                   // 한 줄 출력 후 줄바꿈
	}

	return 0;
}
