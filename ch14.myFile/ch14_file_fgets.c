#include <stdio.h>

int main(void)
{
	char buffer[100]={0};

	printf("문자열 입력: ");

	// fgets는 최대 n-1개의 문자를 읽고 마지막에 '\0'을 자동으로 추가한다.
	fgets(buffer, sizeof(buffer), stdin);

	// 문자열 끝의 '\n' 제거
	buffer[strcspn(buffer, "\n")] = '\0';

	puts("입력한 내용:");
	puts(buffer);

	return 0;
}
