#include <stdio.h>

union Data {
    int   i;
    float f;
    char  c;
};

int main(void)
{
    union Data data;
    data.i = 100;   // int로 저장.
    data.f = 3.14f; // 같은 메모리에 float로 덮어씀 (이전 값 소멸)
    data.c = 'A';   // 같은 메모리에 char로 덮어씀 (이전 값 소멸)

    printf("%c\n", data.c);

    return 0;
}
