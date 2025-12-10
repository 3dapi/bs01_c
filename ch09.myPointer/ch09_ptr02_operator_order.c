#include <stdio.h>

int main(void)
{
	int arrInt[] = {1000, 2000, 3000, 4000};
	int* ptr = arrInt;
	printf("%d, %d\n", ++*ptr++, *ptr);

	return 0;
}
