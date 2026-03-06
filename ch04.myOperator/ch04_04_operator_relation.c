#include <stdio.h>

int main(void)
{
    int a = 10, b = 20;

    int r1 = (a == b) ;  // 0 (거짓)
    int r2 = (a != b) ;  // 1 (참)
    int r3 = (a < b)  ;   // 1 (참)
    int r4 = (a >= 10); // 1 (참)

    printf("(%d == %d) => %d\n", a, b, r1);
    printf("(%d != %d) => %d\n", a, b, r2);
    printf("(%d <  %d) => %d\n", a, b, r3);
    printf("(%d >= 10) => %d\n",    a, r4);

    printf("\n------------------------------------------------\n\n");
    int x = 5;
    int r = x + 3 > 10;   // (x + 3) > 10 으로 해석 → 8 > 10 → 0

    // 1) 조건문(if)
    int score = 100;
    if(score >= 90) {
        printf("A 등급\n");
    }
    printf("\n");

    // 2) 반복문(while)
    int n = 10;
    while(n != 0) {
        n--;
        printf("%d\n", n);
    }

    // 3) 범위 검사
    if(0 <= x && x < 100) {
        // x가 0 이상 100 미만
        printf("x(%d) 는 0이상 100 미만\n", x);
    }

    return 0;
}