#include <stdio.h>

enum COLOR_RGBA
{
	COLOR_RED,                      // 0
	COLOR_GREEN,                    // 1
	COLOR_BLUE,                     // 2
	COLOR_ALPHA,                    // 3
	COLOR_RGBA_END = COLOR_ALPHA,   // 3
	COLOR_TEMP = 100,               // 100
	COLOR_OTHER = 100,              // 100
	COLOR_MAX = COLOR_ALPHA + 1,    // 4
	COLOR_X  = 'B',                 // 66
	COLOR_PI = (int)3.14,           // 3
};




int main(void)
{
	enum COLOR_RGBACC
	{
		COLOR_RECCD ,          // 0
	};

	enum COLOR_RGBA cc = COLOR_PI;
	int dd = COLOR_PI;
	
	return 0;
}
