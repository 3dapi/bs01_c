예시 코드 (학생 참고용, 과제 안내에 선택적으로 포함 가능)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// [min, max] 범위 난수
int GetRandom(int min, int max)
{
    return min + rand() % (max - min + 1);
}

int Add(int a, int b) { return a + b; }
int Sub(int a, int b) { return a - b; }
int Mul(int a, int b) { return a * b; }
int Div(int a, int b) { return a / b; }
int Mod(int a, int b) { return a % b; }

int main(void)
{
    srand((unsigned int)time(NULL));

    int a = GetRandom(1, 100);
    int b = GetRandom(1, 100);

    printf("%d + %d = %d\n", a, b, Add(a, b));
    printf("%d - %d = %d\n", a, b, Sub(a, b));
    printf("%d * %d = %d\n", a, b, Mul(a, b));
    printf("%d / %d = %d\n", a, b, Div(a, b));
    printf("%d %% %d = %d\n", a, b, Mod(a, b));

    return 0;
}

