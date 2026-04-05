#include <stdio.h>

int main(void)
{
    int arrInt[] = {1000, 2000, 3000, 4000};
    int* ptr = arrInt;
    printf("++*ptr++: %d\n", ++*ptr++);
    printf("*ptr: %d\n", *ptr);

    return 0;
}
