#include <stdio.h>

struct Character
{
    char name[32];
    int hp;
    int attack;
    float positionX, positionY;
};

/*  구조체 선언과 동시에 변수 선언과 초기화도 가능.
// 잘 사용안하는 방식임.
struct Character
{
    char name[32];
    int hp;
    int attack;
    float positionX, positionY;
}
myHero = {"Hello world", 100, 100, 10.0f, 20.0f};
 */

int main(void)
{
    // 구조체 변수 선언.
    struct Character hero;
    // 구조체 변수 선언과 초기화.
    struct Character hero2 = {"Knight", 100, 100, 10.0f, 20.0f};
    return 0;
}
