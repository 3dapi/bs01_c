#include <stdio.h>

int main(void)
{
	char message[64]={0, };
	printf("메시지를 입력하세요: ");
	scanf("%s", message);
	printf("메시지 출력: %s\n", message);
	return 0;
}
