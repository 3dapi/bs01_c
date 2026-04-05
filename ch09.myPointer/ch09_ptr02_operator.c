#include <stdio.h>
 
int main(void)
{
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
 
    // arr[6]와 동일한 표현
    int value = 6[arr];

    printf("6[arr] = %d\n", 6[arr]);


    // 배열 표현식은 암시적으로 포인터로 변환. ptr = &arr[0]; 와 동일.
    int* ptr = arr;

    // 명시적 표현, ptr2 = arr; 와 동일
    int* ptr2 = &arr[0];
 
    for(int i=0; i<9; ++i)
    {
        printf("arr[%d] = %d, *(arr+%d) =%d,  *(ptr+%d) = %d\n"
            , i, i[arr], i, *(arr+i), i, *(ptr+i));
        // arr[i] 대신 i[arr]로 써도 되지만 비추천.
    }
 
    return 0;
}