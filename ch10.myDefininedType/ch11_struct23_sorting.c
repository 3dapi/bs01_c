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

void SortByScore_Descending(void)
{
    int playerCount = sizeof(playerList) / sizeof(playerList[0]);
    // 삽입 정렬
    for(int i = 1; i < playerCount; ++i)
    {
        struct Character key = playerList[i];       // 새로 삽입할 값
        int j = i - 1;

        // key.score 보다 작은 값들을 한 칸씩 오른쪽으로 이동 (내림차순)
        for( ;0 <= j && playerList[j].score < key.score; --j)
        {
            playerList[j + 1] = playerList[j];
        }

        // 비어 있는 위치에 key 삽입
        playerList[j + 1] = key;
    }
}

int main(void)
{
    SortByScore_Descending();

    printf("=== 점수 내림차순 정렬 결과 ===\n");
    int playerCount = sizeof(playerList) / sizeof(playerList[0]);
    for(int i = 0; i < playerCount; ++i)
    {
        printf("%2d: %-12s  Score: %d\n",
               i + 1, playerList[i].name, playerList[i].score);
    }

    return 0;
}
