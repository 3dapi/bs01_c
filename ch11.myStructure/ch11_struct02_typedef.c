#include <stdio.h>

struct Position {
    float x, y;
};
// typedef로 새로운 이름 부여
typedef struct Position Position;
typedef struct Position* PtrPosition;

// 한번에 구조체 별칭 부여.
typedef struct Position Position, *PtrPosition;

/** 이름 없는 구조체.
typedef struct {
    float x, y;
} Position, * PtrPosition;
*/

/** 같은 이름으로 선언
typedef struct Position {
    float x, y;
} Position, * PtrPosition;
*/

int main(void)
{
    // 구조체 변수 선언.
    Position pos;
    PtrPosition ptr;

    // 구조체 변수 선언과 초기화.
    Position pos2 = { 100, 200 };
    PtrPosition ptr2 = &pos2;
    return 0;
}
