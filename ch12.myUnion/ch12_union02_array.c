#include <stdio.h>

union Data {
    int   i;
    float f;
    char  c;
};

// 공용체 배열 선언
union Data arr[3];

int main(void)
{
    arr[0].i = 100;     // 0 번째 요소를 int로 설정
    arr[1].f = 1.23f;   // 1 번째 요소를 float로 설정
    arr[2].c = 'Z';     // 2 번째 요소를 char로 설정

    printf("%d\n", arr[0].i);
    printf("%f\n", arr[1].f);
    printf("%c\n", arr[2].c);

    return 0;
}
