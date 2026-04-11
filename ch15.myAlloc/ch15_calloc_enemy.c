#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Enemy
{
    char name[40];
    int type;
    int attack;
} Enemy;

int main(void)
{
    const int count = 3;

    // Enemy 구조체 count개에 해당하는 연속 메모리 확보 (0으로 초기화)
    Enemy* enemies = (Enemy*)calloc(count, sizeof(Enemy));
    if (!enemies)
    {
        printf("calloc 실패\n");
        return 1;
    }

    // 기본 공격력 설정
    for (int i = 0; i < count; ++i)
    {
        enemies[i].attack = 50;
        sprintf(enemies[0].name, "Goblin%2d", i);
    }

    // 첫 번째 몬스터 설정
    strcpy(enemies[0].name, "Goblin");
    enemies[0].type = 1;
    enemies[0].attack = 80;

    // 출력
    for (int i = 0; i < count; ++i)
    {
        printf("Enemy %d\n", i);
        printf(" name: %s\n", enemies[i].name);
        printf(" type: %d\n", enemies[i].type);
        printf(" attack: %d\n\n", enemies[i].attack);
    }

    free(enemies);
    enemies = NULL;   // 해제 후 안전 처리
    return 0;
}