#include <stdio.h>

union Data {
    int   i;
    float f;
    char  c;
};

int main(void)
{
    union Data value;
    union Data* p = &value;

    p->i = 42;         // 포인터로 접근해 int로 저장
    printf("%d\n", p->i);

    p->c = 'B';        // 같은 메모리를 char로 저장
    printf("%c\n", p->c);

    return 0;
}
