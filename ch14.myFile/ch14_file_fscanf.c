#include <stdio.h>

int main(void)
{
    // 1. 파일 open
    FILE* fp = fopen("data.txt", "r");
    if (!fp)
    {
        printf("파일 열기 실패\n");
        return 1;
    }

    int x, y;
    // 2. fscanf로 파일 읽기.
    if (fscanf(fp, "%d %d", &x, &y) == 2)
    {
        printf("x=%d y=%d\n", x, y);
    }
    else
    {
        printf("파일 읽기 실패\n");
    }
    // 3. 파일 자원 반납.
    fclose(fp);
    fp = NULL;
    return 0;
}
