#include <stdio.h>
#include <stdlib.h>

int* CreateIntArray(size_t n)
{
    int* arr = (int*)malloc(sizeof(int) * n);
    if(!arr)
        return NULL;
    for(int i = 0; i < n; ++i)
        arr[i] = i;
    return arr; // 소유권은 호출자에게 넘어감
}

int main(void)
{
    // 메모리를 확보하고 소유권을 얻음.
    int* arr = CreateIntArray(10);
    if(!arr)
    {
        printf("CreateIntArray 실패\n");
        return 1;
    }
    printf("arr[5] = %d\n", arr[5]);

    // 소유권을 얻은 호출자는 자원을 해제.
    if(arr)
    {
        free(arr);
        arr = NULL;
    }
    return 0;
}