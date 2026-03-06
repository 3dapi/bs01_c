#include <stdio.h>

int main(void)
{
    int arr[10] = {9, 3, 7, 1, 5, 10, 2, 8, 6, 4};
    const int arr_count = sizeof(arr) / sizeof(arr[0]);

    // 정렬 전 출력
    printf("정렬 전: ");
    for(int i = 0; i < arr_count; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 버블 정렬
    for(int pass = 0; pass < arr_count - 1; ++pass)
    {
        int bSorted = 1;
        for(int i = 0; i < arr_count - 1 - pass; ++i)
        {
            if(arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
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
    for(int i = 0; i < arr_count; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}