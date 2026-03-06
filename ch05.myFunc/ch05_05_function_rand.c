#include <stdio.h>
#include <stdlib.h>  // rand()

int main(void)
{
    printf("RAND_MAX = %d\n", RAND_MAX);
    printf("%d\n", rand());
    printf("%d\n", rand());
    printf("%d\n", rand());
    return 0;
}