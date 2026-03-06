#include <stdio.h>

// 함수형 매크로
#define SQUARE(x) ((x) * (x))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define DOUBLE_BAD(x) x * 2
#define DOUBLE(x) ((x) * 2)
#define ADD(a,b) ((a) + (b))

// 문자열화
#define PRINT_VAR(x) printf(#x " = %d\n", x)

// 토큰 결합
#define MAKE_VAR(name) int var_##name = 0

int main(void)
{
    int a = 3;

    // 기본 사용
    int r1 = SQUARE(a + 1);
    printf("SQUARE(a + 1) = %d\n", r1);

    // MAX
    int r2 = MAX(10, 20);
    printf("MAX(10, 20) = %d\n", r2);

    // 괄호 문제 (잘못된 매크로)
    int v1 = DOUBLE_BAD(1 + 2);
    printf("DOUBLE_BAD(1 + 2) = %d\n", v1);

    // 올바른 매크로
    int v2 = DOUBLE(1 + 2);
    printf("DOUBLE(1 + 2) = %d\n", v2);

    // 결과 괄호 문제
    int t = 10 / ADD(2, 3);
    printf("10 / ADD(2,3) = %d\n", t);

    // 문자열화
    int value = 10;
    PRINT_VAR(value);

    // 토큰 결합
    MAKE_VAR(count);
    var_count = 5;
    printf("var_count = %d\n", var_count);

    return 0;
}
