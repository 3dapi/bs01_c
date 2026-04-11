// _Atomic은 C11 표준 기능. 일부 컴파일러에서는 지원이 제한적일 수 있다.

#ifndef __cplusplus
#include <stdatomic.h>
#else
#include <atomic>
#endif
#include <stdio.h>


// 연산 함수들
int Add(int a, int b) { return a + b; }
int Sub(int a, int b) { return a - b; }

// 1. 아토믹 함수 포인터를 전역 변수로 선언하여 공유
#ifndef __cplusplus
_Atomic(int (*)(int, int)) op = Add;
#else
std::atomic<int(*)(int, int)> op = Add;
#endif

// 함수 포인터를 안전하게 교체 (Write)
void SetOp(int (*newOp)(int, int))
{
    atomic_store(&op, newOp);
}

// 함수 포인터를 안전하게 로드하여 호출 (Read)
int CallOp(int a, int b)
{
    int (*f)(int, int) = atomic_load(&op);
    return f(a, b);
}

int main(void)
{
    // 초기 상태 (Add) 호출
    printf("Add: %d\n", CallOp(5, 3)); // 출력: 8

    // 운영 중에 연산 로직을 Sub로 원자적 변경
    SetOp(Sub);
    printf("Sub: %d\n", CallOp(5, 3)); // 출력: 2

    return 0;
}