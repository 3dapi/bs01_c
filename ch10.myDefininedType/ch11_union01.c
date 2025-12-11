#include <stdio.h>

union Data {
	int   i;
	float f;
	char  c;
};

union Data data;
int main(void)
{
	data.i = 10;
	printf("data.i: %d\n", data.i);
	data.f = 220.5;
	printf("data.f: %.2f\n", data.f);
	data.c = 'A';
	printf("data.c: %c\n", data.c);
	return 0;
}
