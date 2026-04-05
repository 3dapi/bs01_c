#include <stdio.h>

enum COLOR_RGBA
{
    COLOR_RED,                      // 0
    COLOR_GREEN,                    // 1
    COLOR_BLUE,                     // 2
    COLOR_ALPHA,                    // 3
    COLOR_RGBA_END = COLOR_ALPHA,   // 3
    COLOR_TEMP = 100,               // 100
    COLOR_OTHER = 100,              // 100
    COLOR_MAX = COLOR_ALPHA + 1,    // 4
    COLOR_X  = 'B',                 // 66
    COLOR_PI = (int)3.14,           // 3
};
void PrintColor(enum COLOR_RGBA color);

// 열거형은 지역적(Local Type)으로도 선언가능.
int UsingLocalTypeEnum(void)
{
    enum COLOR_RGBACC
    {
        COLOR_RGBACC = 0x01223344,
    };

    enum COLOR_RGBACC ret = COLOR_RGBACC;
    return ret;
}

int main(void)
{
    enum COLOR_RGBA color1 = COLOR_PI;
    int color2 = COLOR_PI;

    PrintColor(color1);
    PrintColor(color2);

    printf("LocalTypeEnum: %#010x\n", UsingLocalTypeEnum());
    return 0;
}

void PrintColor(enum COLOR_RGBA color)
{
    printf("Color: %d\n", color);
}