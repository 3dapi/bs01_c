#include <stdio.h>

struct Character
{
    char name[32];
    int hp;
    int attack;
    float positionX, positionY;
};

void PrintCharacter(struct Character c);

int main(void)
{
    // 구조체 변수 선언.
    struct Character hero;
    strcpy(hero.name, "Knight");
    hero.hp = 100;
    hero.attack = 100;
    hero.positionX = 10.0f;
    hero.positionY = 20.0f;

    // 구조체 변수 선언과 초기화.
    struct Character hero2 = {"Archer", 150, 90, 10.0f, 20.0f};

    // 멤버 지정 초기화
    struct Character hero3 =
    {
        .name = "Mage",
        .hp = 90,
        .attack = 150,
        .positionX = 10.0f,
        .positionY = 20.0f
    };

    PrintCharacter(hero);
    PrintCharacter(hero2);
    PrintCharacter(hero3);
    return 0;
}

void PrintCharacter(struct Character c)
{
    printf("이름: %s, HP: %d\n", c.name, c.hp);
}
