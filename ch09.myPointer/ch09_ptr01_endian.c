#include <stdio.h>

int main(void)
{
	int x = 0x12345678;
	char* p = (char*)&x;
	// 메모리에 실제로 저장된 바이트 순서를 확인한다.
	printf("%#x 저장 순서 => %#x %#x %#x %#x\n", x, p[0], p[1], p[2], p[3]);

	if(p[0] == 0x78)
		printf("현재 시스템은 Little Endian 입니다.\n");
	else if(p[0] == 0x12)
		printf("현재 시스템은 Big Endian 입니다.\n");
	else
		printf("알 수 없는 Endian 입니다.\n");

	return 0;
}
