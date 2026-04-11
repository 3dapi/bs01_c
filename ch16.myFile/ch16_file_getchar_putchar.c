#include <stdio.h>

int main(void)
{
    printf("문자를 입력하세요 (종료: Ctrl+Z 후 Enter)\n");
    while (1)
    {
        // getchar()는 표준 입력(stdin)에서 문자 1개를 읽는다.
        int ch;
        ch = getchar();

        // EOF이면 루프 종료
        if (EOF == ch)
            break;

        // putchar()는 표준 출력(stdout)에 문자 1개를 출력한다.
        putchar(ch);
        putchar('\n');
    }

    return 0;
}
