#include <stdio.h>

union Data {
    int   i;
    float f;
    char  c;
};

int main(void)
{
    {
        union Data d = { 10 };   // d.i = 10 으로 초기화됨
    }
    {
        //union Data d = { 10, 3.14f };   // 허용되지 않음: 하나만 초기화 가능
    }
    {
        union Data d = { .f = 3.14f };   // f 멤버로 초기화
    }
    {
        union Data d = {.i = 10, .f = 3.14f};   // 마지막 값으로 덮어씀
        printf("%f\n", d.f);
    }
    return 0;
}
