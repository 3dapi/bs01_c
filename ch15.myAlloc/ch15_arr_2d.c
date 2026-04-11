#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int rows = 3;
    int cols = 4;
    int arrayCount = rows * cols;
    int* arr2d = (int*)malloc(sizeof(int) * arrayCount);
    if (!arr2d)
        return 1;

    // 2D 배열처럼 값을 채우기.
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            arr2d[r * cols + c] = r * 10 + c;
        }
    }

    // 인덱스 계산을 통해 2D 배열처럼 출력.
    for (int i = 0; i < arrayCount; ++i)
    {
        int r = i / cols; // 행 인덱스 계산.
        int c = i % cols; // 열 인덱스 계산.
        printf("%3d ", arr2d[r * cols + c]);

        if (c+1 == cols)
            printf("\n");
    }

    free(arr2d);
    arr2d = NULL;

    return 0;
}
