#include <stdio.h>

int main(void)
{
    int a = 10 + 3;   // 13
    int b = 10 - 3;   // 7
    int c = 10 * 3;   // 30
    int d = 10 / 3;   // 3 (정수 나눗셈 → 소수점 버림)
    int e = 10 % 3;   // 1 (모듈로 연산)

    printf("10 + 3 => %d\n", a);
    printf("10 - 3 => %d\n", b);
    printf("10 * 3 => %d\n", c);
    printf("10 / 3 => %d\n", d);
    printf("10 %% 3 => %d\n", e);

    return 0;
}