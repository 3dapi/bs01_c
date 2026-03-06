#include <stdio.h>

int main(void)
{
    // 정수 승격
    char a = 10;
    char b = 20;
    printf("sizeof(a +10)  = %zu\n", sizeof(a + 10));
    printf("sizeof(a + b)  = %zu\n", sizeof(a + b));

    // 정수 승격 signed → unsigned
    char c = -1;
    unsigned int d = 1;
    printf("sizeof(c + d)  = %zu, %d + %u = %u\n", sizeof(c + d), c, d, c+d);

    return 0;
}
