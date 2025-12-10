#include <stdio.h>

int main(void)
{
	char name[64]={0,};
	fgets(name, sizeof(name), stdin);
	// 문자열 끝의 '\n' 제거
	name[strcspn(name, "\n")] = '\0';
	printf("name: %s\n", name);
	return 0;
}
