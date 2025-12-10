#include <stdio.h>

int main(void)
{
    int x = 0, y = 0;
    printf("두 정수를 입력하세요: ");
    scanf("%d %d", &x, &y);
    printf("합: %d\n", x + y);
    return 0;
}
