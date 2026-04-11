#include <stdio.h>
#include <string.h>

struct Character {
    char name[32];
    int hp;
    int score;
};

// 전역 구조체 배열 (13명)
struct Character playerList[] = {
    {"Knight",      100, 320},
    {"Archer",      150, 250},
    {"Mage",        120, 410},
    {"Priest",       90, 180},
    {"Warrior",     180, 500},
    {"Rogue",       110, 290},
    {"Paladin",     160, 470},
    {"Hunter",      130, 330},
    {"Druid",        95, 210},
    {"Necromancer", 140, 390},
    {"Berserker",   170, 520},
    {"Monk",        105, 260},
    {"Samurai",     155, 450}
};

void FindCharacterArrayByName(const char* name)
{
    int playerCount = sizeof(playerList) / sizeof(playerList[0]);
    for (int i = 0; i < playerCount; ++i)
    {
        if (strcmp(playerList[i].name, name) == 0)
        {
            printf("검색됨: %s  (HP: %d, Score: %d)\n",
                   playerList[i].name,
                   playerList[i].hp,
                   playerList[i].score);
            return;
        }
    }

    printf("'%s' 이름의 캐릭터를 찾을 수 없습니다.\n", name);
}

void FindCharacterPtrByName(const char* name)
{
    int playerCount = sizeof(playerList) / sizeof(playerList[0]);

    struct Character* ptr = playerList; // &playerList[0]
    struct Character* ptrEnd = ptr + playerCount;

    for(; ptr != ptrEnd; ++ptr)
    {
        if (strcmp(ptr->name, name) == 0)
        {
            printf("검색됨: %s  (HP: %d, Score: %d)\n",
                   ptr->name,
                   ptr->hp,
                   ptr->score);
            return;
        }
    }

    printf("'%s' 이름의 캐릭터를 찾을 수 없습니다.\n", name);
}

int main(void)
{
    FindCharacterArrayByName("Warrior");
    FindCharacterArrayByName("Druid");
    FindCharacterArrayByName("Unknown");

    FindCharacterPtrByName("Warrior");
    FindCharacterPtrByName("Druid");
    FindCharacterPtrByName("Unknown");
    return 0;
}
