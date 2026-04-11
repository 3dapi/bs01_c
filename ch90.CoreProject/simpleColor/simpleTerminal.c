#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TerminalUtil.h"

#define FPS_DELAY_MS   16
#define EVENT_TICK     12
#define MAP_MIN_Y      6

int main(void)
{
	// 1. 초기화 (마우스 및 ANSI 활성화)
	InitAnsi();
	srand((unsigned int)time(NULL));
	ClearScreen();

	int px = 20, py = 10;
	int timerCounter = 0;
	int key = 0;

	printf("================= 16색상 & WASD/방향키 테스트 =================\n");
	printf(" 조작: [방향키] 또는 [W,A,S,D] | 종료: [Q]\n");
	printf(" 특징: 200ms 마다 16가지 색상 중 하나가 랜덤하게 출력.\n");
	printf("===============================================================\n");

	while(1)
	{
		// 3. 키보드 입력 처리 (기존 초록색 유지)
		if(HasKeyboardEvent())
		{
			key = GetKeyboard();
			if(key == KEY_QUIT || key == KEY_QUIT_CAP) break;

			MoveCursor(px, py); printf(" ");

			int moveKeyUp = 0, moveKeyDown = 0, moveKeyLeft = 0, moveKeyRight = 0;

			if(key == KEY_EXTENDED || key == KEY_NULL)
			{
				key = GetKeyboard();
				if(key == KEY_UP)
					moveKeyUp = 1;
				else if(key == KEY_DOWN)
					moveKeyDown =1;
				else if(key == KEY_LEFT)
					moveKeyLeft = 1;
				else if(key == KEY_RIGHT)
					moveKeyRight = 1;
			}
			else
			{
				if(key == 'w' || key == 'W')
					moveKeyUp = 1;
				else if(key == 's' || key == 'S')
					moveKeyDown = 1;
				else if(key == 'a' || key == 'A')
					moveKeyLeft = 1;
				else if(key == 'd' || key == 'D')
					moveKeyRight = 1;
			}

			if(moveKeyUp)
				py--;
			else if(moveKeyDown)
				py++;
			else if(moveKeyLeft)
				px--;
			else if(moveKeyRight)
				px++;


			if(px < 1)
				px = 1;
			if(py < MAP_MIN_Y) py = MAP_MIN_Y;

			MoveCursor(px, py);
			SetColor(COLOR_BRIGHT_GREEN);
			printf("@");
			SetColor(COLOR_RESET);
		}

		// 4. 랜덤 색상 이벤트 및 루프 관리
		if(timerCounter >= EVENT_TICK)
		{
			SetColorXY(GetRandom(1, 50), GetRandom(MAP_MIN_Y + 1, 20), GetRandom(31, 36));
			printf("■");
			SetColor(COLOR_RESET);
			timerCounter = 0;
		}

		SleepMilliSecond(FPS_DELAY_MS);
		timerCounter++;
	}

	ClearScreen();
	return 0;
}
