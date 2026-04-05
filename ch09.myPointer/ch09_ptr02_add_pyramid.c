#include <stdio.h>

int main(void)
{
    int arr[] = { 1, 3, 5, 7, 9, 11, 13 };
    int* left  = arr;
    int* right = arr + 6;

    while (left < right)
    {
        printf("%d + %d = %d\n", *left, *right, *left + *right);
        ++left;     // 왼쪽에서 오른쪽으로 이동
        --right;    // 오른쪽에서 왼쪽으로 이동
    }

    return 0;
}