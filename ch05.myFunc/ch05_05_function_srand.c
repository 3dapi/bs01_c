#include <stdio.h>
#include <stdlib.h>  // rand()
#include <time.h>    // time()

int main(void)
{
    time_t t = time(NULL); //time_t는 시간을 표현하기 위한 정수 타입
    printf("time_t: %lld\n", (long long)t); //time_t 의 크기는 구현마다 다름. int형의 가장 큰 크기로 정수 승격.

    srand((unsigned int)time(NULL));  // 실행할 때마다 달라짐

    // 일반적인 범위 (minVal ~ maxVal)
    int minVal = 100, maxVal = 200;
    int r = minVal + rand() % (maxVal - minVal + 1);

    printf("%d\n", r);	
    return 0;
}
