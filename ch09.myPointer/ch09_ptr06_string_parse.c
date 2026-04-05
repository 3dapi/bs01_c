#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    printf("=== 1. 문자열 → 숫자 변환 ===\n");

    // atoi
    int i = atoi("123");
    printf("atoi(\"123\") = %d\n", i);

    // atof
    double f = atof("3.14");
    printf("atof(\"3.14\") = %f\n", f);

    // strtol (가장 중요)
    char* endPtr;
    long v = strtol("123abc", &endPtr, 10);
    printf("strtol(\"123abc\") = %ld\n", v);
    printf("변환 후 남은 문자열 = \"%s\"\n", endPtr);

    // strtoul
    unsigned long uv = strtoul("4294967295", NULL, 10);
    printf("strtoul = %lu\n", uv);

    // strtod
    double dv = strtod("3.14pi", &endPtr);
    printf("strtod = %f\n", dv);
    printf("변환 후 남은 문자열 = \"%s\"\n\n", endPtr);


    printf("=== 2. 문자열 길이 분석 ===\n");

    // strspn
    size_t len1 = strspn("abcde12345", "abcde");
    printf("strspn(\"abcde12345\", \"abcde\") = %zu\n", len1);

    // strcspn
    size_t len2 = strcspn("abcde12345", "123");
    printf("strcspn(\"abcde12345\", \"123\") = %zu\n", len2);


    printf("\n=== 3. 활용 예제 ===\n");

    // 숫자 문자열 검사
    char input[] = "12345abc";

    size_t digitLen = strspn(input, "0123456789");

    if (digitLen == strlen(input))
    {
        printf("모든 문자가 숫자입니다.\n");
    }
    else
    {
        printf("숫자가 아닌 문자가 포함되어 있습니다.\n");
    }

    // 앞부분 숫자만 추출
    char input2[] = "789xyz";
    long num = strtol(input2, &endPtr, 10);

    printf("앞부분 숫자: %ld\n", num);
    printf("나머지 문자열: %s\n", endPtr);

    return 0;
}
