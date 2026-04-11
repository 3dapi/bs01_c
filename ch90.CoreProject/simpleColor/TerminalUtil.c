#include <stdio.h>
#include <conio.h>   // _kbhit, _getch 사용을 위한 헤더
#include <windows.h>
#include "TerminalUtil.h"

void EnableANSI(void)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwMode = 0;
	GetConsoleMode(hOut, &dwMode);
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(hOut, dwMode);
	SetHideCursor();
}

void SetShowCursor(void)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hOut, &cursorInfo);

	cursorInfo.bVisible = TRUE;    // 다시 표시
	SetConsoleCursorInfo(hOut, &cursorInfo);
}

void SetHideCursor(void)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hOut, &cursorInfo);

	cursorInfo.bVisible = FALSE;   // 커서 숨김
	SetConsoleCursorInfo(hOut, &cursorInfo);
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

