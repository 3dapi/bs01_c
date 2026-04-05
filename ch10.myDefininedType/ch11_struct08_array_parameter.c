#include <stdio.h>

struct Character
{
    char name[32];
    int hp;
    int attack;
    float positionX, positionY;
};

void PrintParty(struct Character party[], int count);
//void PrintParty(struct Character* party, int count);

int main(void)
{
    // 구조체 배열 선언과 초기화.
    struct Character party[3] =
    {
        {"Knight", 100, 15, 10.0f, 20.0f},
        {"Archer", 80, 10, 15.0f, 18.0f},
        { "Mage" , 60, 25, 12.0f, 22.0f},
    };

    // 호출
    int partyCount = sizeof(party) / sizeof(party[0]);
    PrintParty(party, partyCount);

    return 0;
 }

void PrintParty(struct Character party[], int count)
//void PrintParty(struct Character* party, int count)
{
    for (int i = 0; i < count; ++i)
        printf("%s (%d)\n", party[i].name, party[i].hp);
}