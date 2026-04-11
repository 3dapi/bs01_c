#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TerminalUtil.h"

#define FPS_DELAY_MS   16
#define EVENT_TICK     12    // 200ms (16ms * 12)
#define MAP_MIN_Y      6

int main(void)
{
	EnableANSI();
	srand((unsigned int)time(NULL));
	ClearScreen();

	// 사용 가능한 16가지 색상을 배열로 관리
	int colorTable[16] =
	{
		COLOR_BLACK,
		COLOR_RED,
		COLOR_GREEN,
		COLOR_YELLOW, 
		COLOR_BLUE,
		COLOR_MAGENTA,
		COLOR_CYAN,
		COLOR_WHITE,
		COLOR_BRIGHT_BLACK,
		COLOR_BRIGHT_RED,
		COLOR_BRIGHT_GREEN,
		COLOR_BRIGHT_YELLOW,
		COLOR_BRIGHT_BLUE,
		COLOR_BRIGHT_MAGENTA,
		COLOR_BRIGHT_CYAN,
		COLOR_BRIGHT_WHITE
	};

	int px = 20, py = 10;
	int timerCounter = 0;
	int key = 0;

	printf("================= 16색상 & WASD/방향키 테스트 =================\n");
	printf(" 조작: [방향키] 또는 [W,A,S,D] | 종료: [Q]\n");
	printf(" 특징: 200ms 마다 16가지 색상 중 하나가 랜덤하게 출력.\n");
	printf("===============================================================\n");

	while(1)
	{
		if(HasKeyboardEvent())
		{
			key = GetKeyboard();
			if(key == KEY_QUIT || key == KEY_QUIT_CAP)
				break;

			MoveCursor(px, py); printf(" "); // 잔상 지우기

			// 입력 처리 (방향키 + WASD)
			if(key == KEY_EXTENDED || key == KEY_NULL)
			{
				key = GetKeyboard();
				if(key == KEY_UP)
					py--;
				else if(key == KEY_DOWN)
					py++;
				else if(key == KEY_LEFT)
					px--;
				else if(key == KEY_RIGHT) px++;
			}
			else
			{
				if(key == 'w' || key == 'W')
					py--;
				else if(key == 's' || key == 'S')
					py++;
				else if(key == 'a' || key == 'A')
					px--;
				else if(key == 'd' || key == 'D') px++;
			}

			if(px < 1)
				px = 1;
			if(py < MAP_MIN_Y)
				py = MAP_MIN_Y;

			MoveCursor(px, py);
			SetColor(COLOR_BRIGHT_GREEN); // 플레이어는 밝은 초록
			printf("@");
			SetColor(COLOR_RESET);
		}

		// 2초마다 16색 중 랜덤 출력
		if(timerCounter >= EVENT_TICK)
		{
			int rx = (rand() % 50) + 1;
			int ry = (rand() % 10) + MAP_MIN_Y + 1;
			
			// 16개 색상 인덱스(0~15) 중 랜덤 선택
			int randomIdx = rand() % 16;
			int selectedColor = colorTable[randomIdx];

			SetColorXY(rx, ry, selectedColor);
			printf("■"); // 색상을 더 잘 보기 위해 사각형 출력
			SetColor(COLOR_RESET);

			timerCounter = 0;
		}

		SleepMilliSecond(FPS_DELAY_MS);
		timerCounter++;
	}

	ClearScreen();
	return 0;
}

