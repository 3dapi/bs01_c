#include <stdio.h>
#define BUFFER_SIZE 4096

int main(void)
{
    FILE* src = fopen("source.bin", "rb");
    if (!src)
    {
        printf("원본 파일 열기 실패\n");
        return 1;
    }

    FILE* dest = fopen("copy.bin", "wb");
    if (!dest)
    {
        printf("대상 파일 열기 실패\n");
        fclose(src);
        return 1;
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while (1)
    {
        bytes_read = fread(buffer, 1, BUFFER_SIZE, src);
        if (bytes_read == 0)
            break;

        if (fwrite(buffer, 1, bytes_read, dest) != bytes_read)
        {
            printf("파일 쓰기 오류\n");
            break;
        }
    }

    fclose(src);
    fclose(dest);

    printf("파일 복사 완료\n");
    return 0;
}
