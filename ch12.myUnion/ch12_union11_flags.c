#include <stdio.h>
struct FlagsBits {
    unsigned int flagA   : 1;  // 1비트
    unsigned int flagB   : 1;  // 1비트
    unsigned int flagC   : 1;  // 1비트
    unsigned int reserved: 29; // 나머지 비트
};

typedef union {
    struct {
        unsigned int flagA   : 1;  // 1비트
        unsigned int flagB   : 1;  // 1비트
        unsigned int flagC   : 1;  // 1비트
        unsigned int reserved: 29; // 나머지 비트
    } bits;
    unsigned int value;
} Flags;

int main(void)
{
    struct FlagsBits fb = { 0 };

    fb.flagA = 1;
    fb.flagB = 0;
    fb.flagC = 1;

    // 개별 비트에 이름으로 접근 가능
    printf("A=%u B=%u C=%u\n",
           fb.flagA, fb.flagB, fb.flagC);

    Flags f = {0};

    // 1) 비트 단위로 플래그 설정
    f.bits.flagA = 1;
    f.bits.flagC = 1;

    // 2) 전체 값을 한 번에 확인
    printf("value = 0x%08X\n", f.value);

    // 3) 전체 값을 직접 대입한 뒤 다시 비트로 해석
    f.value = 0x00000002;
    printf("A=%u B=%u C=%u\n",
           f.bits.flagA,
           f.bits.flagB,
           f.bits.flagC);

    return 0;
}
