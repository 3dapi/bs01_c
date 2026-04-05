#include <stdio.h>

int main(void)
{
    {
        int arr[32]={0};

        char* ptr1 = NULL;
        int* ptr2  = NULL;
        void* ptr3 = NULL;
        struct POINT* ptr4 = NULL;

        sizeof(arr );   // 128  (32 * sizeof(int))
        sizeof(ptr1);   // 8(64bit) 또는 4 (32bit)
        sizeof(ptr2);   // 8(64bit) 또는 4 (32bit)
        sizeof(ptr3);   // 8(64bit) 또는 4 (32bit)
        sizeof(ptr4);   // 8(64bit) 또는 4 (32bit)

        printf("sizeof(arr ) = %zu\n", sizeof(arr ));
        printf("sizeof(ptr1) = %zu\n", sizeof(ptr1));
        printf("sizeof(ptr2) = %zu\n", sizeof(ptr2));
        printf("sizeof(ptr3) = %zu\n", sizeof(ptr3));
        printf("sizeof(ptr4) = %zu\n", sizeof(ptr4));
    }
    {
        int arr[4];
        int* ptr = arr;       // arr → &arr[0]
        int* ptr2 = &arr[0];  // ptr과 ptr2는 동일한 주소

        printf("ptr  address = 0x%p\n", ptr );
        printf("ptr2 address = 0x%p\n", ptr2);
    }

    return 0;
}
