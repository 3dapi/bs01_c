#include <stdio.h>

void ParameterLife(int x)
{
    x = x + 10;
    printf("x inside ParameterLife = %d\n", x);
}

int main(void)
{
    int a = 5;
    ParameterLife(a);
    printf("a in main = %d\n", a);

    return 0;
}

// 출력:
// x inside ParameterLife = 15
// a in main = 5
