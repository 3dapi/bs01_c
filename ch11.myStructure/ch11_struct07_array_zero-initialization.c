#include <stdio.h>

struct Character
{
    char name[32];
    int hp;
    int attack;
    float positionX, positionY;
};

int main(void)
{
    // 구조체 배열 선언과 초기화.
    struct Character party[3] =
    {
        { "Knight", 100, 15, 10.0f, 20.0f },
        { "Archer",  80 },  // 나머지 멤버는 자동으로 0 또는 NULL
    };

    for (int i = 0; i < 3; ++i)
    {
        printf("캐릭터 %d: %s (HP: %d)\n", i, party[i].name, party[i].hp);
    }

    return 0;
 }
