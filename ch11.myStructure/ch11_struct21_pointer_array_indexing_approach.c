#include <stdio.h>

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

int GetMaxScoreIndex_Array(void)
{
    int playerCount = sizeof(playerList) / sizeof(playerList[0]);
    int maxIndex = 0;

    for (int i = 1; i < playerCount; ++i)
    {
        if (playerList[i].score > playerList[maxIndex].score)
        {
            maxIndex = i;
        }
    }

    return maxIndex;
}

int GetMaxScoreIndex_Pointer(void)
{
    int playerCount = sizeof(playerList) / sizeof(playerList[0]);
    struct Character* ptr = playerList; // &playerList[0]
    struct Character* maxPtr = ptr;  // 현재 최대 점수를 가진 캐릭터 포인터

    for (int i = 1; i < playerCount; ++i)
    {
        if((ptr + i)->score > maxPtr->score)
        {
            maxPtr = (ptr + i);
        }
    }
    return (int)(maxPtr - ptr); // 시작포인터와의 차이 = 인덱스.
}

int main(void)
{
    int indexArray  = GetMaxScoreIndex_Array();
    int indexPointer = GetMaxScoreIndex_Pointer();

    printf("[첨자 연산자 방식] ");
    printf("최고 점수 캐릭터: %s (Score: %d)\n",
           playerList[indexArray].name,
           playerList[indexArray].score);

    printf("\n[포인터 방식] ");
    printf("최고 점수 캐릭터: %s (Score: %d)\n",
           playerList[indexPointer].name,
           playerList[indexPointer].score);

    return 0;
}
