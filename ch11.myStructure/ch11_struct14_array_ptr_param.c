#include <stdio.h>

struct Character {
    char name[32];
    int hp;
};

void HealAll(struct Character* ptrCharacter, int count, int amount)
{
    for (int i = 0; i < count; ++i)
        ptrCharacter[i].hp += amount;   // 포인터에도 배열처럼 첨자 연산자([]) 사용 가능.
}

int main(void)
{
    struct Character party[] = {
        { "Knight", 100 },
        { "Archer",  80 },
        { "Mage",    60 }
    };

    int characterCount = sizeof(party) / sizeof(party[0]);
    int amount = 20;

    HealAll(party, characterCount, amount);  // 배열은 포인터로 변환 (party == &party[0])

    for (int i = 0; i < 3; ++i)
        printf("%s : %d HP\n", party[i].name, party[i].hp);

    return 0;
}
