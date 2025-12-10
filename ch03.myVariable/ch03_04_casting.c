#include <stdio.h>

int main(void)
{
	int a = 128;
	long long b = a;

	float f = (float)3.1415926535897932384626;
	int n   = (int)f;

	printf("b = %lld, %d \n",b,n);
	return 0;
}
