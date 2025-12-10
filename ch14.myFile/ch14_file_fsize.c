#include <stdio.h>

#include <stdio.h>

long GetFileSize(FILE* fp);

int main(void)
{
    FILE* fp = fopen("player.dat", "rb");
    if (fp)
    {
        long size = GetFileSize(fp);
        printf("파일 크기: %ld bytes\n", size);
        fclose(fp);
    }

    return 0;
}

long GetFileSize(FILE* fp)
{
    if (!fp)
        return -1;

    long current = ftell(fp);        // 현재 위치 저장
    if (current == -1)
        return -1;

    if (fseek(fp, 0, SEEK_END) != 0)
        return -1;

    long size = ftell(fp);           // 파일 끝 위치 = 파일 크기

    fseek(fp, current, SEEK_SET);    // 원래 위치로 복원

    return size;
}
