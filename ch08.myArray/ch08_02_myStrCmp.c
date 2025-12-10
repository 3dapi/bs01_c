#include <stdio.h>

int myStrCmp(const char s1[], const char s2[]);

int main(void)
{
	char str1[] = "Hello world";
	char str2[] = "Hello";

	int cmpValue = myStrCmp(str1, str2);

	printf("string compare: %d\n", cmpValue);

	return 0;
}

int myStrCmp(const char s1[], const char s2[])
{
	int i = 0;

	while(s1[i] != '\0' && s2[i] != '\0')
	{
		if(s1[i] > s2[i])
			return +1;
		if(s1[i] < s2[i])
			return -1;
		++i;
	}

	// 여기까지 왔다는 것은 둘 중 하나가 끝났다는 의미
	if(s1[i] == '\0' && s2[i] == '\0')
		return 0;

	// s1이 짧음
	if(s1[i] == '\0')
		return -1;

	// s2가 짧음
	return +1;
}
