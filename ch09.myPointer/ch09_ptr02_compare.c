#include <stdio.h>

int main(void)
{
    // 의미있는 비교: 같은 배열 내의 포인터끼리 비교.
    {
        int arr[] = {10, 20, 30, 40, 50, 60};

        int* p = &arr[1];
        int* q = &arr[5];

        printf("p < q : %d\n", p < q);      //  1 (의미 있는 비교)
        printf("p == q: %d\n", p == q);     //  0
        printf("q - p : %lld\n", q - p);    //  4 (q가 p보다 4개의 요소 뒤에 있다.)
        printf("p - q : %lld\n", p - q);    // -4 (p가 q보다 4개의 요소 앞에 있다.)
    }
    // 의미 없는 비교: 서로 다른 객체의 포인터끼리 비교.
    {
        int a = 10;
        int b = 20;

        int* p = &a;
        int* q = &b;

        printf("%d\n", p < q);  // 서로 다른 객체 → 의미 없는 비교
    }

    return 0;
}