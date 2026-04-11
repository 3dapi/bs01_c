#include <stdio.h>
#include <stdlib.h>

int CompareInt(const void* a, const void* b)
{
    int lhs = *(const int*)a;
    int rhs = *(const int*)b;

    if(lhs < rhs) return -1;
    if(lhs > rhs) return  1;
    return 0;
}

int main(void)
{
    int arr[] = {42, 7, 19, 3, 25};
    int size = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, size, sizeof(int), CompareInt);

    for(int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}