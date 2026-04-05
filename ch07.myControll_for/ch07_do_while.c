#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int value=-1;

    do
    {
        printf("0 이상의 정수를 입력하세요: ");
        scanf("%d", &value);
    } while(0<=value);

    printf("입력한 값: %d\n", value);
    return 0;
}
