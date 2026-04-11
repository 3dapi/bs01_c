#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int arr2d[10][20] = { 0 };
    int row_count = sizeof(arr2d) / sizeof(arr2d[0]);       // 행 개수
    int col_count = sizeof(arr2d[0]) / sizeof(arr2d[0][0]); // 열 개수

    // 2차원 배열에 값 채우기
    for (int r = 0; r < row_count; ++r)
    {
        for (int c = 0; c < col_count; ++c)
        {
            arr2d[r][c] = (rand() % RAND_MAX) - RAND_MAX/2;
        }
    }

    int maxValue = 0x80000000;
    int minValue = 0x7FFFFFFF;
    int evenCount= 0;
    int oddCount = 0;
    int positiveCount = 0;
    int negativeCount = 0;

    // 2차원 배열 원소에서 값 찾기
    for (int r = 0; r < row_count; ++r)
    {
        for (int c = 0; c < col_count; ++c)
        {
            if (maxValue < arr2d[r][c]) // 최대 값
            {
                maxValue = arr2d[r][c];
            }
            if (minValue > arr2d[r][c]) // 최소값
            {
                minValue = arr2d[r][c];
            }

            if (arr2d[r][c] % 2)
            {
                ++oddCount;             // 홀수 개수.
            }
            else
            {
                ++evenCount;            // 짝수 개수.
            }

            if (arr2d[r][c] > 0)        // 양수.
            {
                ++positiveCount;
            }
            else if (arr2d[r][c] < 0)   // 음수.
            {
                ++negativeCount;
            }
        }
    }
    printf("========================================\n");
    printf("Max: %4d\n", maxValue);
    printf("Min: %4d\n", minValue);
    printf("odd Count : %4d\n", oddCount);
    printf("even Count: %4d\n", evenCount);
    printf("positive Count: %4d\n", positiveCount);
    printf("negative Count: %4d\n", negativeCount);


    // 1차원 배열처럼 처리
    int totalCount = row_count * col_count;
    maxValue = 0x80000000;
    minValue = 0x7FFFFFFF;
    evenCount = 0;
    oddCount = 0;
    positiveCount = 0;
    negativeCount = 0;
    for (int i = 0; i < totalCount; ++i)
    {
        int r = i / col_count;      // row index
        int c = i % col_count;      // column index
        int value = arr2d[r][c];

        if (maxValue < value)
        {
            maxValue = value;
        }
        if (minValue > value)
        {
            minValue = value;
        }

        if (arr2d[r][c] % 2)
        {
            ++oddCount;        // 홀수 개수.
        }
        else
        {
            ++evenCount;        // 짝수 개수.
        }

        if (value > 0)          // 양수.
        {
            ++positiveCount;
        }
        else if (value < 0)     // 음수.
        {
            ++negativeCount;
        }
    }
    printf("\n\n");
    printf("========================================\n");
    printf("Max: %4d\n", maxValue);
    printf("Min: %4d\n", minValue);
    printf("odd Count : %4d\n", oddCount);
    printf("even Count: %4d\n", evenCount);
    printf("positive Count: %4d\n", positiveCount);
    printf("negative Count: %4d\n", negativeCount);

    return 0;
}
