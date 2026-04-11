#include <stdio.h>
#include <stdlib.h>

// VLA
// rows, cols는 런타임에 결정된다.
// arr의 실제 타입은: int (*arr)[cols]
// 즉, "cols개짜리 int 배열을 가리키는 포인터"
void PrintMatrix(int rows, int cols, int arr[rows][cols])
{
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            printf("%3d ", arr[r][c]);
        }
        printf("\n");
    }
}

int main(void)
{
    int rows = 3;
    int cols = 4;

    // 연속된 메모리 확보
    int (*dyn)[cols] = (int (*)[cols])malloc(sizeof(int) * rows * cols);
    if (!dyn)
        return 1;

    // 값 채우기
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            dyn[r][c] = r * 10 + c;
        }
    }

    PrintMatrix(rows, cols, dyn);

    free(dyn);
    dyn = NULL;

    return 0;
}
