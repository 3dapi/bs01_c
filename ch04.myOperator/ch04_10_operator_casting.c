#include <stdio.h>

int main(void)
{
    double x = 3.9;
    int    a = (int)x;    // 실수 → 정수, 소수점 이하 버림 → a = 3
    printf("x => %f, a => %d \n", x, a);

    int big  = 1000;
    char c   = (char)big; // int → char, 상위 비트가 잘릴 수 있음
    printf("big => %d, c => %d \n", big, c);

    int n1 = 5;
    int n2 = 2;

    double r1 = n1 / n2;  // 정수 나눗셈 → 2 (소수점 버려짐), r1 = 2.0
    double r2 = (double)n1 / n2;
    // n1이 먼저 double로 변환되므로 전체 연산이 실수 나눗셈으로 처리된다.
    // 결과적으로 (double)n1 / (double)n2 와 같은 효과를 가진다.

    printf("n1 => %d, n2 => %d \n", n1, n2);
    printf("r1 => %f, r2 => %f \n", r1, r2);

    return 0;
}
