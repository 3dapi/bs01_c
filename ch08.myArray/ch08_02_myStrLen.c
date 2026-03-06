#include <stdio.h>

size_t myStrLen(char str[]);

int main(void)
{
    char myString[] = "Hello world";
    size_t len = myStrLen(myString);

    printf("myString Length: %zu\n", len);

    return 0;
}

size_t myStrLen(char str[])
{
    if(NULL == str)
        return 0;   // 널 포인터면 길이는 0.

    size_t len = 0;
    // 널문자 전까지가 문자열의 길이.
    while(str[len] != '\0')
    {
        ++len;
    }
    return len;
}
