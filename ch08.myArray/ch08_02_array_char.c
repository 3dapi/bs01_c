#include <stdio.h>

int main(void)
{
    char array1[] = { 'H', 'e', 'l', 'l', 'o' };
    
    // 문자열 리터럴 → 자동으로 '\0' 포함
    // 내부: 'H','e','l','l','o','\0' → 총 6바이트
    char myStr1[] = "Hello";        // 문자열 리터럴 + 명시적 '\0' 추가

    // 내부: 'H','e','l','l','o','\0','\0' → 총 7바이트
    // 문자열 리터럴 자체에 이미 '\0'이 있기 때문에 하나 더 추가됨
    char myStr2[] = "Hello\0";      // 포인터 → 문자열 리터럴을 가리킴

    // 포인터 변수 자체는 문자열 크기가 아니라 주소 크기를 가짐
    const char* myStr3 = "Hello";
    printf("array(\"Hello\")   : %zu\n", sizeof(myStr1)); // 6
    printf("array(\"Hello\\0\") : %zu\n", sizeof(myStr2)); // 7
    printf("pointer(\"Hello\") : %zu\n", sizeof(myStr3)); // 8 (64bit 기준)
    printf("literal(\"Hello\") : %zu\n", sizeof("Hello")); // 6 ('\0' 포함)

    return 0;
}
