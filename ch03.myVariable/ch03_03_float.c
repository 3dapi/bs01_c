#include <stdio.h>

int main(void)
{
    // 부동 소수점 숫자 출력
    double PI = 3.14159265358979;
    printf("%f\n", PI);
    printf("%16.10f\n", PI);
    printf("%.10f\n", PI);

    // 부동 소수점 오차 누적 예
    double a = 1e16;
    double b = -1e16;
    double c = 1.;

    // 부동소수점 정밀도 문제로 연산 순서에 따라 결과가 달라질 수 있음
    printf("%f\n", (a + b) + c); // 1
    // 매우 큰 값과 작은 값을 더할 때 작은 값이 반올림으로 사라질 수 있음
    printf("%f\n", a + (b + c)); // 0

    // 부동소수점 반복 연산 오차
    // 0.1은 이진 부동소수점으로 정확히 표현되지 않기 때문에 반복 덧셈을 하면 오차가 누적될 수 있다.
    float stored = 0.0F;
    for(int i=0; i<100; ++i)
        stored += 0.1F;
    printf("%f \n", stored);

    // 정수에서 부동 소수점으로 변환 시 정밀도 손실
    int i = 1234567890;
    float f = i;   // int → float 변환 (정밀도 손실 가능)

    printf("int: %d => float:%f\n",i, f);  // 반올림된 값 출력

    return 0;
}
