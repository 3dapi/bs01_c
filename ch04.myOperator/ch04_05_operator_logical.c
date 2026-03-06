#include <stdio.h>

int main(void)
{
    int a = 10, b = 20;

    int r1 = (a < 15 && b > 10);   // 1 (참)
    int r2 = (a > 15 || b > 10);   // 1 (참)
    int r3 = !(a == 10)        ;   // 0 (a == 10이 참 → NOT → 거짓)

    printf("a = %d , b = %d\n", a, b);
    printf("(a < 15 && b > 10) => %d\n", r1);
    printf("(a > 15 || b > 10) => %d\n", r2);
    printf("!(a == 10)         => %d\n", r3);

    return 0;
}