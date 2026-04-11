#include <stdio.h>

struct PaddingCSN {
    char  c;    // 1바이트
    short s;    // 2바이트
    int   n;    // 4바이트
};
struct PaddingCNS {
    char  c;    // 1바이트
    int   n;    // 4바이트
    short s;    // 2바이트
};
struct PaddingSCN {
    short s;    // 2바이트
    char  c;    // 1바이트
    int   n;    // 4바이트
};
struct PaddingSNC {
    short s;    // 2바이트
    int   n;    // 4바이트
    char  c;    // 1바이트
};
struct PaddingNCS {
    int   n;    // 4바이트
    char  c;    // 1바이트
    short s;    // 2바이트
};
struct PaddingNSC {
    int   n;    // 4바이트
    short s;    // 2바이트
    char  c;    // 1바이트
};

int main(void)
{
    size_t sizeCSN = sizeof(struct PaddingCSN); // char(1) + 패딩(1) + short(2) + int(4) = 8 bytes
    size_t sizeCNS = sizeof(struct PaddingCNS); // char(1) + 패딩(3) + int(4) + short(2) + 패딩(2) = 12 bytes
    size_t sizeSCN = sizeof(struct PaddingSCN); // short(2) + char(1) + 패딩(1) + int(4) = 8 bytes
    size_t sizeSNC = sizeof(struct PaddingSNC); // short(2) + 패딩(2) + int(4) + char(1) + 패딩(3) = 12 bytes
    size_t sizeNCS = sizeof(struct PaddingNCS); // int(4) + char(1) + 패딩(1) + short(2) = 8 bytes
    size_t sizeNSC = sizeof(struct PaddingNSC); // int(4) + short(2) + char(1) + 패딩(1) = 8 bytes

    printf("Size of struct PaddingCSN: %zu bytes\n", sizeCSN);
    printf("Size of struct PaddingCNS: %zu bytes\n", sizeCNS);
    printf("Size of struct PaddingSCN: %zu bytes\n", sizeSCN);
    printf("Size of struct PaddingSNC: %zu bytes\n", sizeSNC);
    printf("Size of struct PaddingNCS: %zu bytes\n", sizeNCS);
    printf("Size of struct PaddingNSC: %zu bytes\n", sizeNSC);

    return 0;
}
