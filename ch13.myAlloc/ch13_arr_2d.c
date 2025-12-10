#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int rows = 3;
    int cols = 4;

    int* arr2d = (int*)malloc(sizeof(int) * rows * cols);
    if (!arr2d)
        return 1;

    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            arr2d[r * cols + c] = r * 10 + c;
        }
    }

    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            printf("%3d ", arr2d[r * cols + c]);
        }
        printf("\n");
    }

    free(arr2d);
    arr2d = NULL;

    return 0;
}
