#include <stdio.h>

int main(void)
{
    int x = 4;
    int y = 7;
    printf("%d\n", x & y);
    printf("%d\n", x | y);
    printf("%d\n", x ^ y);
    printf("%d\n", ~x   );
    printf("%d\n", x <<y);
    printf("%d\n", x >>y);
	
    unsigned int a = 6;    // 0000 0110
    unsigned int b = 10;   // 0000 1010
    unsigned int r1 = a & b;   // 0000 0010  (2)
    unsigned int r2 = a | b;   // 0000 1110  (14)
    unsigned int r3 = a ^ b;   // 0000 1100  (12)
    unsigned int r4 = ~a   ;   // 0xFFFFFFF9 1111 1001  (비트 반전)
    unsigned int r5 = a << 1;  // 0000 1100  (12)
    unsigned int r6 = b >> 1;  // 0000 0101  (5)

	printf(" %u & %u => %u\n", a, b, r1);
	printf(" %u | %u => %u\n", a, b, r2);
	printf(" %u ^ %u => %u\n", a, b, r3);
	printf("~%u      => %u\n", a,    r4);
	printf(" %u << 1 => %u\n", a,    r5);
	printf(" %u >> 1 => %u\n", a,    r6);

    // 특정 비트 켜기(OR)
    unsigned flags = 0;   // 3번째 비트 ON
    flags = flags | 0x0004;   // 3번째 비트 ON

    // 특정 비트 끄기(AND + NOT)
    flags = flags & ~0x04;  // 3번째 비트 OFF

	// 특정 비트 토글(XOR)
	flags = flags ^ 0x04;   // 3번째 비트 반전

    signed char r = -8;   // 1111 1000 (2의 보수 표현 가정)
    r = r >>1;    // 1111 1100
    r = r >>1;    // 1111 1110
    r = r >>1;    // 1111 1111
    r = r >>1;    // 1111 1111

    int i = 0x12345678;
    int j = !i;
    printf("%d %d\n", !i, ~i);

    return 0;
}