#include <stdio.h>

int main(void)
{
int x = 0x12345678;
int* p = &x;
int** pp = &p;
int*** ppp = &pp;

printf("%#x\n", ***ppp);  // 0x12345678
printf("%#x\n", **&*&*&*&*&*&p); // 0x12345678
	return 0;
}
