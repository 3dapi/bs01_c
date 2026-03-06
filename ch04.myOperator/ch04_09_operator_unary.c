#include <stdio.h>

int main(void)
{
    int a = 5;
    int b = -a;      // 단항 -, 부호 반전 → -5
    int c = !a;      // 논리 NOT → 0
    int d = ~a;      // 비트 NOT → 비트 반전 (unsigned에서 사용 권장)

    int* p = &a;     // 주소 연산자 &, a의 주소 저장
    int e = *p;      // 간접 참조 연산자 *, p가 가리키는 값을 읽음 → 5

    printf("a => %d\n", a);
    printf("b => %d\n", b);
    printf("c => %d\n", c);
    printf("d => %d\n", d);
    printf("p => 0x%p\n", p);
    printf("e => %d\n", e);

    return 0;
}