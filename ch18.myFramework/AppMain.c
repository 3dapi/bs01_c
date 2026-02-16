#include <stdio.h>
#include "AppData.h"
#include "AppInput.h"
#include "AppGameLogic.h"

// 시스템 초기화
int AppInit(void)
{
	printf("AppInit\n");

	if(0>InitData())
		return -1;
	if(0>InitInput())
		return -1;
	if(0>InitGameLogic())
		return -1;
	return 0;
}

// 시스템 자원 해제
int AppDestroy(void)
{
	printf("AppDestroy\n");
	DestroyGameLogic();
	DestroyInput();
	DestroyData();
	return 0;
}

int AppRun(void)
{
	int hr = 0;
	printf("AppRun\n");
	while(1)
	{
		if(0>(hr = UpdateInput()))
			break;
		if(0>(hr = UpdateGameLogic()))
			break;
	}
	// hr 처리.
	// ...
	// AppInit 관련 해제.
	AppDestroy();
	return 0;
}
