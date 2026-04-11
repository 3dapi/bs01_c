#include <stdio.h>

size_t myStrCpy(char dst[], size_t dest_size, const char src[]);

int main(void)
{
    char strSource[] = "Hello world, welcome!!!"; // source string
    char strDest[20] = {0};          // copied string

    size_t len = myStrCpy(strDest, sizeof(strDest), strSource);

    printf("string copy: %zu - %s\n", len, strDest);

    return 0;
}

size_t myStrCpy(char dst[], size_t dest_size, const char src[])
{
    if(0 == dest_size)  // 크기 0이면 복사할 수 없으므로 0 반환.
        return 0;

    size_t n=0;
    dest_size -= 1;     // 널문자 저장 공간을 위해 1 감소.

    for(;'\0' != src[n] && 0<dest_size; ++n, --dest_size)
    {
        dst[n] = src[n];
    }
	dst[n] = '\0';      // 널문자 저장.

    return n;
}
