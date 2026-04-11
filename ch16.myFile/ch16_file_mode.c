#include <stdio.h>

int main(void)
{
    // 1. 파일 열기 (쓰기 모드)
    FILE* fp = fopen("example.txt", "w");
    // 2. 파일 유효 체크
    if (!fp)
    {
        printf("fopen 실패\n");
        // 또는
        // perror("fopen 실패");

        return 1;
    }

    // 3. 파일에 데이터 기록
    fprintf(fp, "Hello File\n");

    // 4. 파일 닫기 (자원 반환)
    fclose(fp);
    fp = NULL;
    return 0;
}