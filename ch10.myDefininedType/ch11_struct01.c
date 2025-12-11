#include <stdio.h>

struct Character
{
	char name[32];
	int hp;
	int attack;
	float positionX, positionY;
}
myHero = { 	"Hello world", 100, 100, 10.0f, 20.0f };


int main(void)
{
	{
		// 이미 있는 구조체에 별칭 부여.
		typedef struct Position Position;
		typedef struct Position* PtrPosition;
	}
	{
		// 이름 없는 구조체.
		typedef struct {
			float x, y;
		} Position, * PtrPosition;
	}
	{
		// 같은 이름으로 선언
		typedef struct Position {
			float x, y;
		} Position, * PtrPosition;
	}

	struct A {
		char c;   // 1바이트
		int  n;   // 4바이트
	};
	struct B {
		int  n;   // 4바이트
		char c;   // 1바이트
	};

	size_t sizeA = sizeof(struct A); // 8바이트 (패딩 3바이트 포함)
	size_t sizeB = sizeof(struct B); // 8바이트 (패딩 3바이트 포함)

	static cc;
	int c ={100}, d= {299};
	enum COLOR_RGBACC
	{
		COLOR_RECCD ,          // 0
	};
	cc = 199;
	
	int aa[] ={1,2,3};

	int** pp = &aa;
	
	return 0;
}
