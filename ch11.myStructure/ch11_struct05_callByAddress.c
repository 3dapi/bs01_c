#include <stdio.h>

struct Character
{
    char name[32];
    int hp;
    int attack;
    float positionX, positionY;
};

// call by address 방식으로 구조체를 전달하는 함수 선언.
void HealCharacter(struct Character* c, int amount);

// const 구조체 포인터 — 읽기 전용 전달
void PrintCharacter(const struct Character* ptrCharacter);

int main(void)
{
    // 구조체 변수 선언.
    struct Character hero;
    strcpy(hero.name, "Knight");
    hero.hp = 100;
    hero.attack = 15;
    hero.positionX = 10.0f;
    hero.positionY = 20.0f;

    // 구조체 변수 선언과 초기화.
    struct Character hero2 = {"Odysseus", 120, 13, 20.0f, 250.0f};

    // 멤버 지정 초기화
    struct Character hero3 =
    {
        .name = "Archer",
        .hp = 9999,
        .attack = 9999,
        .positionX = 100.0f,
        .positionY = 2000.0f
    };
    // 구조체 변수 call by address 로 전달.(const)
    HealCharacter(&hero, 10);
    HealCharacter(&hero2, 100);
    HealCharacter(&hero3, 300);

    // 함수 호출
    // 구조체 변수의 주소를 전달해서 hero hp 값이 변경되도록 한다.
    PrintCharacter(&hero);
    PrintCharacter(&hero2);
    PrintCharacter(&hero3);
    return 0;
}

void HealCharacter(struct Character* c, int amount)
{
    (*c).hp += amount;   // 구조체 포인터 접근(정확하지만 괄호가 많음)
    //c->hp += amount;   // -> 는 (*c).hp 의 문법적 축약형
}

// const 구조체 포인터 — 읽기 전용 전달 함수 정의.
void PrintCharacter(const struct Character* ptrCharacter)
{
    // 만약 ptrCharacter->hp += ... 시도시 컴파일 에러 발생
    printf("이름: %s, HP: %d\n", ptrCharacter->name, ptrCharacter->hp);
}
