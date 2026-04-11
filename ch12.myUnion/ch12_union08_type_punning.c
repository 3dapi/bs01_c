#include <stdio.h>

union Number {
    int   i;
    float f;
};

int main(void)
{
    union Number n;

    n.f = 3.14f;
    printf("%x\n", n.i);   // float의 비트 패턴을 정수 형식으로 출력.

    return 0;
}
