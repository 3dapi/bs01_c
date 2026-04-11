#include <stdio.h>

int Add(int a, int b) { return a + b; }

int main(void)
{
    printf("%p\n", Add);
    printf("%p\n", &Add);
    return 0;
}