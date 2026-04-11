#pragma once
#ifndef TERMINAL_UTIL_H
#define TERMINAL_UTIL_H

// --- 표준 8색 (Standard Colors) ---
#define COLOR_RESET         0
#define COLOR_BLACK         30
#define COLOR_RED           31
#define COLOR_GREEN         32
#define COLOR_YELLOW        33
#define COLOR_BLUE          34
#define COLOR_MAGENTA       35
#define COLOR_CYAN          36
#define COLOR_WHITE         37

// --- 밝은 8색 (Bright Colors) ---
#define COLOR_BRIGHT_BLACK   90  // Gray
#define COLOR_BRIGHT_RED     91
#define COLOR_BRIGHT_GREEN   92
#define COLOR_BRIGHT_YELLOW  93
#define COLOR_BRIGHT_BLUE    94
#define COLOR_BRIGHT_MAGENTA 95
#define COLOR_BRIGHT_CYAN    96
#define COLOR_BRIGHT_WHITE   97

// --- 키보드 및 기타 상수 (기존 동일) ---
#define KEY_EXTENDED 224
#define KEY_NULL     0
#define KEY_UP       72
#define KEY_DOWN     80
#define KEY_LEFT     75
#define KEY_RIGHT    77
#define KEY_W 'w'
#define KEY_A 'a'
#define KEY_S 's'
#define KEY_D 'd'
#define KEY_QUIT     'q'
#define KEY_QUIT_CAP 'Q'

// 함수 선언
void EnableANSI(void);
void SetShowCursor(void);
void SetHideCursor(void);
void MoveCursor(int x, int y);
void SetColor(int color_code);
void SetColorXY(int x, int y, int color_code);
void ClearScreen(void);
void SleepMilliSecond(unsigned int millisecond);
int HasKeyboardEvent(void);
int GetKeyboard(void);
int GetRandom(int minVal, int maxVal);
#endif