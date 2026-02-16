#include <stdio.h>
#include <string.h>
#include "AppInput.h"

typedef struct Input
{
	unsigned char key[256];
}  Input;

static Input g_input;

// 입력 시스템 초기화.
int InitInput(void)
{
	printf("InitInput\n");
	memset(g_input.key, 0, sizeof(unsigned char) * 256);
	return 0;
}

// 입력 시스템 업데이트.
int UpdateInput(void)
{
	printf("UpdateInput\n");

	char name[256]={0, };
	fgets(name, sizeof(name), stdin);
	name[strcspn(name, "\n")] = '\0';
	printf("input: %s\n", name);
	return 0;
}

// 입력 시스템 해제.
int DestroyInput(void)
{
	printf("DestroyInput\n");
	return 0;
}
