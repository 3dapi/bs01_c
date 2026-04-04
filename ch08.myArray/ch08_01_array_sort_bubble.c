#include <stdio.h>

int main(void)
{
    int buffer[10] = {9, 3, 7, 1, 5, 10, 2, 8, 6, 4};
    const int bufferCount = sizeof(buffer) / sizeof(buffer[0]);

    // 정렬 전 출력
    printf("정렬 전: ");
    for(int i = 0; i < bufferCount; ++i)
    {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    // 버블 정렬
    for(int pass = 0; pass < bufferCount - 1; ++pass)
    {
        int bSorted = 1;
        for(int i = 0; i < bufferCount - 1 - pass; ++i)
        {
            if(buffer[i] > buffer[i + 1])
            {
                int temp = buffer[i];
                buffer[i] = buffer[i + 1];
                buffer[i + 1] = temp;
                bSorted = 0;    // 정렬 안된 경우.
            }
        }
        // 정렬 된 경우 중단.
        if(bSorted)
        {
            break;
        }
    }

    // 정렬 후 출력
    printf("정렬 후: ");
    for(int i = 0; i < bufferCount; ++i)
    {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    return 0;
}