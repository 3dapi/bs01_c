#include <stdio.h>

typedef struct Status
{
    int hp;
    int attack;
} Status;

typedef struct Position
{
    float x;
    float y;
} Position;

typedef struct
{
    char name[32];
    Status status;
    Position pos;
} Character;

int main(void)
{
    // 구조체 변수 선언과 초기화.
    Character hero = {
        "Knight",
        {100, 15},      // Status 멤버.
        {10.0f, 20.0f}, // Position 멤버.
    };

    return 0;
 }
