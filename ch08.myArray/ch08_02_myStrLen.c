#include <stdio.h>

int myStrLen(char str[]);

int main(void)
{
	char myString[] = "Hello world";
	int len = myStrLen(myString);

	printf("myString Length: %d\n", len);

	return 0;
}

int myStrLen(char str[])
{
	int len = 0;
	// 널문자 전까지가 문자열의 길이.
	while(str[len] != '\0')
	{
		++len;
	}
	return len;
}
