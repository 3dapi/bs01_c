#include <stdio.h>

int main(void)
{
    char buffer[5];
    int value = 123456789;

    int len = snprintf(buffer, sizeof(buffer), "%d", value);
    if (len >= sizeof(buffer))
    {
        printf("문자열이 잘렸습니다.\n");
    }

    printf("%s\n", buffer);
    return 0;
}
