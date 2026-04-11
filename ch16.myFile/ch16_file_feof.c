#include <stdio.h>

#define BUFFER_SIZE 64

int main(void)
{
    FILE* fp = fopen("item_info.csv", "rb");
    if(!fp)
    {
        printf("파일 열기 실패\n");
        return 1;
    }

    char buffer[BUFFER_SIZE] = {0};
    size_t bytes_read = 0;

    while(1)
    {
        bytes_read = fread(buffer, 1, BUFFER_SIZE, fp);

        if(bytes_read == 0)
        {
            if(feof(fp))
                printf("파일 끝(EOF)에 도달했습니다.\n");
            else if(ferror(fp))
                printf("읽기 오류가 발생했습니다.\n");

            break;
        }

        // 읽은 데이터 처리 (예: 출력)
        for(size_t i = 0; i < bytes_read; ++i)
        {
            putchar(buffer[i]);
        }
    }

    fclose(fp);
    fp = NULL;

    return 0;
}