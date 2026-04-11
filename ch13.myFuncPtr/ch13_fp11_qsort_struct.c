#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Player
{
    char name[32];
    int level;
    int hp;
    int attack;
    float posX, posY;
} Player;

// Player의 name을 기준으로 비교하는 함수
// qsort에서 사용할 경우 캐스팅 필요 (비권장)
int ComparePlayerName(const Player* lhsPlayer, const Player* rhsPlayer)
{
    // Windows: _stricmp: 대소문자 구분 없이 문자열 비교
#if defined(_WIN32) || defined(_WIN64)
    return _stricmp(lhsPlayer->name, rhsPlayer->name);
#else
    return strcasecmp(lhsPlayer->name, rhsPlayer->name);
#endif
}

// Player의 level 기준 비교 함수
// qsort 요구 형태 (const void*, const void*)
int ComparePlayerLevel(const void* player1, const void* player2)
{
	const Player* lhsPlayer = (const Player*)player1;
	const Player* rhsPlayer = (const Player*)player2;

    if(lhsPlayer->level > rhsPlayer->level)
        return -1;
    if(lhsPlayer->level < rhsPlayer->level)
        return 1;
    return 0;
}

void PrintPlayerInfo(const Player* player)
{
    printf("player:%8s %3d\n", player->name, player->level);
}

int main(void)
{
    Player player[] =
    {
        // name,     level, hp,  attack, posX, posY
        { "Dante",    18,   120, 45,     10.0f, 20.0f },
        { "Iris",     12,    90, 30,     15.0f, 25.0f },
        { "Leon",     15,   140, 35,     20.0f, 30.0f },
        { "Selena",   20,   100, 50,      5.0f, 10.0f },
        { "Arthur",   10,   160, 25,     12.0f, 18.0f },
        { "Luna",     14,    95, 28,      8.0f, 16.0f },
        { "Victor",   16,   150, 40,     22.0f, 35.0f }
    };

    int size = sizeof(player) / sizeof(player[0]);

    // sort by name
	// qsort의 비교 함수: (const void*, const void*)
	// 캐스팅 가능하지만 코드가 복잡해지고 가독성이 떨어짐
    qsort(player, size, sizeof(Player), (int (*)(const void*, const void*))ComparePlayerName);
    printf("\n===== Player Lists =====\n");
    for(int i = 0; i < size; ++i)
        PrintPlayerInfo(&player[i]);

    // sort by level
    qsort(player, size, sizeof(Player), ComparePlayerLevel);

    printf("\n===== Player Level =====\n");
    for(int i = 0; i < size; ++i)
        PrintPlayerInfo(&player[i]);
    printf("\n");

    return 0;
}