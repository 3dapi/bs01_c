#include <stdio.h>

int main(void)
{
    int a = 10;

    printf("a => %d\n", a);
    a += 3;   printf("a => %d\n", a);   // a = a + 3  → 13
    a -= 2;   printf("a => %d\n", a);   // a = a - 2  → 11
    a *= 4;   printf("a => %d\n", a);   // a = a * 4  → 44
    a /= 2;   printf("a => %d\n", a);   // a = a / 2  → 22
    a %= 5;   printf("a => %d\n", a);   // a = a % 5  → 2

    printf("\n");
    // 비트 연산과 함께 사용하는 예
    unsigned int x = 0x01;  // 0001

    printf("x => %#08x\n", x);
    x |= 0x04;  printf("x => %#08x\n", x);  // 0000 0101 (비트 2 켜기)
    x &= ~0x01; printf("x => %#08x\n", x);  // 0000 0100 (비트 0 끄기)
    x ^= 0x08;  printf("x => %#08x\n", x);  // 0000 1100 (비트 3 토글)
    x <<= 1;    printf("x => %#08x\n", x);  // 0001 1000 (왼쪽으로 1비트 이동)
    x >>= 2;    printf("x => %#08x\n", x);  // 0000 0010 (오른쪽으로 2비트 이동)

    return 0;
}