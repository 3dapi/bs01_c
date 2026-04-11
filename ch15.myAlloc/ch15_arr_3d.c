#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int width  = 10;
    int height = 5;
    int depth  = 2;

    int ***ppp = NULL;

    ppp = (int***)malloc(sizeof(int**) * width);

    for (int i = 0; i < width; ++i)
    {
        ppp[i] = (int**)malloc(sizeof(int*) * height);

        for (int j = 0; j < height; ++j)
        {
            ppp[i][j] = (int*)malloc(sizeof(int) * depth);

            for (int k = 0; k < depth; ++k)
                ppp[i][j][k] = k + j * depth + i * depth * height;
        }
    }

    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < height; ++j)
        {
            for (int k = 0; k < depth; ++k)
                printf("array[%d][%d][%d] = %d\n", i, j, k, ppp[i][j][k]);
        }
    }

    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < height; ++j)
            free(ppp[i][j]);

        free(ppp[i]);
    }

    free(ppp);
    ppp = NULL;

    return 0;
}
