#include <stdio.h>

int main(void)
{
	int val1 = 10;
	int val2 = 20;
	int val3 = 30;
	int val4 = 40;

	// 포인터 배열
	int *ptr[] = {&val1, &val2, &val3, &val4};

	int array_count = sizeof(ptr) / sizeof(ptr[0]);
	for(int i=0; i< array_count; ++i)
	{
		printf("Value %d: %d\n", i+1, *ptr[i]);
	}

	return 0;
}
