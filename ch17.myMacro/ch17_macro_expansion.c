#include <stdio.h>

// 기본 매크로
#define VALUE 10
#define DOUBLE(x) ((x) * 2)

// 중첩 매크로
#define BASE 5
#define ADD_BASE(x) ((x) + BASE)

// 재확장 확인용
#define TRIPLE(x) (DOUBLE(x) + (x))

int main(void)
{
    // 1️. 재확장.
    int r = DOUBLE(VALUE);
    printf("DOUBLE(VALUE) = %d\n", r);

    // 2️. 매크로 중첩.
    int v = ADD_BASE(3);
    printf("ADD_BASE(3) = %d\n", v);

    // 3️. 매크로 안에서 매크로 호출.
    int t = TRIPLE(4);
    printf("TRIPLE(4) = %d\n", t);

    return 0;
}
