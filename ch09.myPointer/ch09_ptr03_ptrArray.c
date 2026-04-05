#include <stdio.h>
 
int main(void)
{
    int arr[] = {
          1,  2,  3,  4,
          5,  6,  7,  8,
          9, 10, 11, 12,
         13, 14
    };
 
    // 주의: 배열 포인터를 이용해 배열을 4개 단위로 해석하는 예제
    // 이 코드는 타입이 일치하지 않는 포인터를 사용하여
    // 동일한 메모리를 다른 방식으로 해석하는 예제이다.
    // arr의 타입은 int[14]이며, &arr은 int (*)[14]이므로
    // int (*)[4]와는 서로 다른 타입이다.
    // 이러한 방식은 배열 경계를 넘어 접근할 수 있으며,
    // 정의되지 않은 동작(Undefined Behavior)을 유발할 수 있다.
    // → 이후 예제에서 typedef(CHUNK)를 사용한 안전한 방법을 제시한다.
    int (*ptr_arr)[4] = &arr;

    for (int i = 0; i < 4; ++i)
    {
        printf("ptr_arr %d: [%2d %2d %2d %2d]\n",
            i + 1,
            *(ptr_arr[i] + 0),
            *(ptr_arr[i] + 1),
            *(ptr_arr[i] + 2),
            *(ptr_arr[i] + 3));
    }
 
    return 0;
}