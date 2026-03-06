#include <stdio.h>
#include <stdlib.h>  // rand()

int main(void)
{
    // 0 ~ 9 범위
    int v = rand() % 10;

    // 일반적인 범위 (minVal ~ maxVal)
    int r = minVal + rand() % (maxVal - minVal + 1);

    // 주사위: 1 ~ 6
    int dice = 1 + rand() % 6;

    // 20~50 범위
    int x = 20 + rand() % (50 - 20 + 1)
    

    printf("%d\n", v);
    printf("%d\n", r);
    printf("%d\n", dice);
    printf("%d\n", x);	
    return 0;
}