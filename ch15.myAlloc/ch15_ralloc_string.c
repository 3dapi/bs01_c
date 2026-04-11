#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t len = 0;          // 현재 문자열 길이(널 제외)
    size_t cap = 4;          // 현재 버퍼 용량(널 포함)
    char* buffer = (char*)malloc(cap);
    if (!buffer)
    {
        printf("malloc 실패\n");
        return 1;
    }
    buffer[0] = '\0';

    printf("문자열 입력(Enter로 종료): ");

    int ch;
    while (1)
    {
        ch = getchar();                 // 문자 하나 입력.
        if(ch == '\n' || ch == EOF)     // 개행 또는 EOF 이면 종료.
            break;

        // len + 1(새 문자) + 1('\0') 가 cap을 넘으면 확장
        if (len + 2 > cap)
        {
            size_t new_cap = cap * 2;
            char* tmp = (char*)realloc(buffer, new_cap);
            if (!tmp)
            {
                printf("realloc 실패\n");
                free(buffer);
                buffer = NULL;
                return 1;
            }

            buffer = tmp;
            cap = new_cap;
        }

		buffer[len] = (char)ch;  // 새 문자 추가. 
		buffer[++len] = '\0';    // 널 문자로 종료.
    }

    printf("결과: %s\n", buffer);
    printf("len=%zu, cap=%zu\n", len, cap);

    free(buffer);
    buffer = NULL;

    return 0;
}