
#include <stdio.h>

int main(void)
{
	printf("%5d\n", 42);    // "   42"
	printf("%.2f\n",3.14159);     // "3.14"
	printf("%.5s\n","HelloWorld"); // "Hello"

	printf("%-10s\n","Hi");   // "Hi        "

	printf("%05d\n",42);     // "00042"

	printf("%+d\n",7);       // "+7"

	printf("%#x\n",255);     // "0xff"


	return 0;
}