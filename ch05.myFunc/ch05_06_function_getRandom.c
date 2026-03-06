#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// [minVal, maxVal] 범위 random 값 생성 함수.
int GetRandom(int minVal, int maxVal)
{
    return minVal + rand() % (maxVal - minVal + 1);
}

int main(void)
{
    // 프로그램 시작 시 srand()를 한 번 호출하여 seed를 설정
    srand((unsigned int)time(NULL));
    // 1~6 사이 random 값 얻기.
    int r = GetRandom(1, 6);
    printf("Random: %d\n", r);
    return 0;
}