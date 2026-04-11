#include <stdio.h>

int main(void)
{
    int ch;

    printf("문자를 입력하세요 (종료: Ctrl+Z 후 Enter)\n");

    while (1)
    {
        // getchar()는 표준 입력(stdin)에서 문자 1개를 읽는다.
        ch = getchar();

        // EOF이면 루프 종료
        if (EOF == ch)
            break;

        // putchar()는 표준 출력(stdout)에 문자 1개를 출력한다.
        putchar(ch);
        putchar('\n');
    }

    // stdin  : 표준 입력 스트림 (보통 키보드)
    // stdout : 표준 출력 스트림 (보통 콘솔 화면)

    while (1)
    {
        // fgetc / fputc는 FILE*을 직접 지정하는 형태.
        ch = fgetc(stdin);

        // EOF이면 루프 종료
        if (EOF == ch)
            break;

        fputc(ch, stdout);
        fputc('\n', stdout);
    }

    return 0;
}
