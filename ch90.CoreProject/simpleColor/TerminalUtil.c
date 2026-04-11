#include <stdio.h>
#include <conio.h>   // _kbhit, _getch 사용을 위한 헤더
#include <windows.h>
#include "TerminalUtil.h"

static HANDLE hOutput = NULL;
static HANDLE hInput  = NULL;

void InitAnsi(void)
{
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	hInput  = GetStdHandle(STD_INPUT_HANDLE);
	DWORD dwMode = 0;
	GetConsoleMode(hOutput, &dwMode);
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(hOutput, dwMode);

	EnableShowCursor(FALSE);
}

void EnableShowCursor(int bShow)
{
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hOutput, &cursorInfo);
	cursorInfo.bVisible = bShow? TRUE: FALSE;
	SetConsoleCursorInfo(hOutput, &cursorInfo);
}

void MoveCursor(int x, int y)
{
	// \033[행;열H (좌표는 1부터 시작함에 유의)
	printf("\033[%d;%dH", y, x);
}

void SetColor(int color_code)
{
	// \033[코드m
	printf("\033[%dm", color_code);
}

void SetColorXY(int x, int y, int color_code)
{
	printf("\033[%d;%dH\033[%dm", y, x, color_code);
}

void ClearScreen(void)
{
	// \033[2J: 화면 전체 지우기
	// \033[H : 커서를 좌상단(Home)으로 이동
	printf("\033[2J\033[H");
}

void SleepMilliSecond(unsigned int millisecond)
{
	Sleep(millisecond);
}

int HasKeyboardEvent(void)
{
	return _kbhit();
}

int GetKeyboard(void)
{
	int ret = _getch();
	return ret;
}

int GetRandom(int minVal, int maxVal)
{
	return minVal + rand() % (maxVal - minVal + 1);
}

