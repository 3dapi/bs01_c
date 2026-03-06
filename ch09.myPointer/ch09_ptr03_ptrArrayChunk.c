#include <stdio.h>

#define BLOCK 4
typedef int CHUNK_INT[BLOCK];
void printChunk(int rows, int cols, CHUNK_INT* pChunk);

int main(void)
{
    int arr[][BLOCK] = {
        {10, 11, 12, 13},
        {14, 15, 16, 17},
        {17, 18, 19, 20}
    };
    int rows = sizeof(arr) / sizeof(arr[0]);    // 행의 수.
    printChunk(rows, BLOCK, arr);
    return 0;
}

void printChunk(int rows, int cols, CHUNK_INT* pChunk)
{
    for(int i=0; i<rows; ++i)
    {
        for(int j=0; j<cols; ++j)
        {
            printf("%5d", pChunk[i][j]);
        }
        printf("\n");
    }
}
