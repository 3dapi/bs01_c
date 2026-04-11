#include <stdio.h>

int main(void)
{
    char buffer[5];
    int value = 123456789;

    // 위험: 버퍼보다 긴 문자열을 생성함
    sprintf(buffer, "%d", value);

    printf("%s\n", buffer);
    return 0;
}
