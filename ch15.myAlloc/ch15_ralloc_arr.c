#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 3;
    int* arr = (int*)malloc(sizeof(int) * n);
    if(!arr)
    {
        printf("malloc 실패\n");
        return 1;
    }

    for (int i = 0; i < n; ++i)
        arr[i] = i + 1;

    // 크기 늘리기
    int new_n = 6;
    int* tmp = (int*)realloc(arr, sizeof(int) * new_n);
    if(tmp)
    {
        arr = tmp; // 성공했을 때만 교체

        // 성공했을 때 처리 과정을 이곳에 둔다.
        for (int i = n; i < new_n; ++i)
            arr[i] = (i + 1) * 10;
        for (int i = 0; i < new_n; ++i)
            printf("arr[%d] = %d\n", i, arr[i]);
    }
    else
    {
        printf("realloc 실패\n");
    }
    free(arr);
    arr = NULL;
    return 0;
}