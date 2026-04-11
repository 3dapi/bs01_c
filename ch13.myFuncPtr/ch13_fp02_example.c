#include <stdio.h>

int Add(int a, int b) { return a + b; }
int Sub(int a, int b) { return a - b; }

void PrintResult(int (*op)(int, int), int x, int y)
{
    printf("결과: %d\n", op(x, y));
}

int main(void)
{
    PrintResult(Add, 10, 20);
    PrintResult(Sub, 50, 30);
    return 0;
}