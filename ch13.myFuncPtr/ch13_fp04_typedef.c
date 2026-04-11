#include <stdio.h>

typedef int (*BinaryOp)(int, int);

int Add(int a, int b) { return a + b; }
int Sub(int a, int b) { return a - b; }

int main(void)
{
    BinaryOp op = Add;           // 함수 포인터에 함수 대입
    printf("%d\n", op(10, 20));  // Add 호출

    op = Sub;
    printf("%d\n", op(10, 20));  // Sub 호출
}
