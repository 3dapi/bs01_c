#include <stdio.h>

int main(void)
{
    int a = 10;
    int b = 20;
    int maxVal = (a > b) ? a : b;  // max는 20

    printf("maxVal [%d , %d] => %d\n", a, b, maxVal);

    return 0;
}