#include <stdio.h>

struct Status
{
    int hp;
    int attack;
};

struct Position
{
    float x;
    float y;
};

struct Character
{
    char name[32];
    struct Status status;   // 구조체 Status 포함
    struct Position pos;    // 구조체 Position 포함
};

int main(void)
{
    //// 구조체 변수 선언.
    //struct Character hero;
    //// 구조체 멤버 설정.
    //strcpy(hero.name, "Knight");
    //hero.status.hp = 100;
    //hero.status.attack = 15;
    //hero.pos.x = 10.0f;
    //hero.pos.y = 20.0f;

    // 구조체 변수 선언과 초기화.
    struct Character hero =
    {
        "Knight",
        {100, 15},      // Status 구조체 초기화
        {10.0f, 20.0f}, // Position 구조체 초기화 
    };

    // 중괄호를 생략:
    // 구조체의 멤버들이 선언된 순서대로 차례대로 초기화
    //struct Character hero = { "Knight", 100, 15, 10.0f, 20.0f };

    return 0;
 }
