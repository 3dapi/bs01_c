#include <stdio.h>

int main(void)
{
	//  문자열 배열.
	char *str_list [] = { "Hello", "World", "Hi", "Welcome" };

	int array_count = sizeof(str_list) / sizeof(str_list[0]);
	for(int i=0; i< array_count; ++i)
	{
		printf("%s\n", str_list[i]);
	}

	return 0;
}
