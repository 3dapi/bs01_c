#include <stdio.h>

int main(void)
{
    // 전위연산자.
    int a = 5;
    int b = ++a;   // a는 6이 되고, b는 6
    printf("[a: %d], [b: %d]\n" , a, b);
    int a = 5;
    int b = a++;   // b는 5 → 표현식 종료 후 a는 6으로 변경
    printf("[a: %d], [b: %d]\n" , a, b);

    // 후위연산자.
    int a = 5;
    int b = --a;   // a는 4이 되고, b는 4
    printf("[a: %d], [b: %d]\n" , a, b);
    int a = 5;
    int b = a--;   // b는 5 → 표현식 종료 후 a는 4으로 변경
    printf("[a: %d], [b: %d]\n" , a, b);

    // 이렇게 전위, 후위 섞여있는 경우는 정의되지 않은 동작(UB)이 발생할 수 있다.
    int b1 = 4;
    int b2 = b1++ + ++b1 + b1++ + ++b1 + b1++ + ++b1;
    printf("[b1: %d], [b2: %d]\n", b1, b2);

    // 이런 방법 또한 가독성이 떨어진다.
    int d1 = 4;
    int d2 = d1++, d3 = d1++, d4 = d1++, d5 = d1++, d6 = d1++, d7 = d1++;

    printf("[d1: %d], [d2: %d], [d3: %d], [d4: %d], [d5: %d], [d6: %d], [d7: %d]\n"
            , d1, d2, d3, d4, d5, d6, d7);


    // 포인터 증가 연산자.
    char* p1 = (char*)0x1000;
    printf("p1  : 0x%p\n", p1);
    printf("p1++: 0x%p\n", p1++);
    printf("p1  : 0x%p\n", p1);
    printf("++p1: 0x%p\n", ++p1);

    // 포인터 증가 연산자.
    int* p2 = (int*)0x2000;
    printf("p2  : 0x%p\n", p2);
    printf("p1++: 0x%p\n", p2++);
    printf("p2  : 0x%p\n", p2);
    printf("++p2: 0x%p\n", ++p2);

    return 0;
}