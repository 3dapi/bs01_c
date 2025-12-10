#include <stdio.h>

int main(void)
{
	int maxStar = 4;                        // 최대 별 개수
	for(int i = maxStar; i >= 1; --i)       // i 는 출력할 별의 수
	{
		int numSpace = maxStar - i;         // 공백의 개수
		for(int s = 0; s < numSpace; ++s)   // 1. 공백 출력 과정
		{
			printf(" ");                    // 공백 출력
		}

		for(int j = 0; j < i; ++j)          // 2. 별 출력 과정: i 는 출력할 별의 수
		{
			printf("*");                    // 별 출력
		}
		printf("\n");                       // 3. 줄 바꿈 출력
	}

	return 0;
}
