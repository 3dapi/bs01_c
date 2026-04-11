#include <stdio.h>

int main(void)
{
    // stdin  : 표준 입력 스트림 (보통 키보드)
    // stdout : 표준 출력 스트림 (보통 콘솔 화면)

    printf("문자를 입력하세요 (종료: Ctrl+Z 후 Enter)\n");
    while (1)
    {
        // fgetc / fputc는 FILE*을 직접 지정하는 형태.
        int ch;
        ch = fgetc(stdin);

        // EOF이면 루프 종료
        if (EOF == ch)
            break;

        fputc(ch, stdout);
        fputc('\n', stdout);
    }

    return 0;
}
