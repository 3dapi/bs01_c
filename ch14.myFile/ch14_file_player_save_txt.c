#include <stdio.h>
#define PLAYER_COUNT 5

typedef struct Player
{
    char name[20];
    int level;
    int attack;
    int defense;
} Player;

int main(void)
{
    Player player[PLAYER_COUNT] =
    {
        {"Knight", 10, 25, 15},
        {"Archer", 8, 18, 10},
        {"Wizard", 12, 30, 5},
        {"Paladin", 15, 28, 22},
        {"Assassin", 9, 35, 8}
    };

    FILE* fp = fopen("player.txt", "w");
    if (!fp)
    {
        printf("파일 열기 실패\n");
        return 1;
    }

    for (int i = 0; i < PLAYER_COUNT; ++i)
    {
        fprintf(fp, "%s %d %d %d\n"
            , player[i].name
            , player[i].level
            , player[i].attack
            , player[i].defense);
    }

    fclose(fp);
    return 0;
}
