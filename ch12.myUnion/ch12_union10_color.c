#include <stdio.h>

typedef union {
    struct {
        unsigned char r, g, b, a;
    };
    unsigned char c[4];   // 4바이트 배열로 접근.
    unsigned int value;   // 32비트 정수로 접근.
} Color;

int main(void)
{
    Color c;

    c.r = 255;
    c.g = 128;
    c.b = 0;
    c.a = 255;

    printf("%08X\n", c.value);  // 0xFF8000FF

    return 0;
}
