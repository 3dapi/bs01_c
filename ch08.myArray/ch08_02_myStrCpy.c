#include <stdio.h>

int myStrCpy(char dst[], const char src[]);

int main(void)
{
	char strSource[] = "Hello world"; // source string
	char strDest[256] = {0};          // copied string

	int len = myStrCpy(strDest, strSource);

	printf("string copy: %d - %s\n", len, strDest);

	return 0;
}

int myStrCpy(char dst[], const char src[])
{
	int i = 0;
	while(src[i] != '\0')
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return i;
}

