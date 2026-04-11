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
    //// 구조체 배열 선언.
    //struct Character party[3];

    // 구조체 배열 선언과 초기화.
    struct Character party[3] =
    {
        { "Knight", 100, 15, 10.0f, 20.0f },
        { "Archer",  80, 10, 15.0f, 18.0f },
        { "Mage",    60, 25, 12.0f, 22.0f }
    };

    // 구조체 배열 요소 접근:
    for (int i = 0; i < 3; ++i)
    {
        printf("캐릭터 %d: %s (HP: %d)\n", i, party[i].name, party[i].hp);
    }

    //포인터를 사용한 구조체 배열 접근:
    for (int i = 0; i < 3; ++i)
    {
        // i번째 구조체 요소의 주소를 얻는다 (가장 직관적인 방식)
        struct Character* ptr = &party[i];

        // 위 코드는 다음과 동일하다 (포인터 연산)
        // struct Character* ptr = party + i;

        // 구조체 포인터를 통해 멤버 접근 (-> 사용)
        printf("캐릭터 %d: %s (HP: %d)\n", i, ptr->name, ptr->hp);
    }

    return 0;
}
