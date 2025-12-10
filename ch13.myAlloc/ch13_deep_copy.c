#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Player
{
    char* name;   // 동적 메모리
    int level;
} Player;

Player CreatePlayer(const char* name, int level)
{
    Player p = {0};     // 모든 구조체 값을 0으로 초기화.
    p.level = level;    // 레벨 설정.

    p.name = (char*)malloc(strlen(name) + 1);
    if (!p.name)
    {
        p.level = 0;
        return p; // name이 NULL인 Player 반환
    }

    strcpy(p.name, name);
    return p;
}

// 깊은 복사 함수
Player CopyPlayer(const Player* ref)
{
    Player p2 = {0};    // 모든 구조체 값을 0으로 초기화.

    if (!ref || !ref->name)
        return p2;

    p2.level = ref->level;

    p2.name = (char*)malloc(strlen(ref->name) + 1);
    if (!p2.name)
    {
        p2.level = 0;
        return p2;
    }

    // 새로 할당한 메모리에 실제 데이터를 복사(깊은 복사)
    strcpy(p2.name, ref->name);
    return p2;
}

void DestroyPlayer(Player* p)
{
    if (!p)
        return;

    if (p->name)
    {
        free(p->name);
        p->name = NULL;
    }
    p->level = 0;
}

int main(void)
{
    Player p1 = CreatePlayer("Knight", 10);
    if (!p1.name)
    {
        printf("CreatePlayer 실패\n");
        return 1;
    }

    Player p2 = CopyPlayer(&p1);
    if (!p2.name)
    {
        printf("CopyPlayer 실패\n");
        DestroyPlayer(&p1);
        return 1;
    }

    printf("p1.name=%s, level=%d\n", p1.name, p1.level);
    printf("p2.name=%s, level=%d\n", p2.name, p2.level);
    printf("주소 비교: p1.name=%p, p2.name=%p\n", (void*)p1.name, (void*)p2.name);

    DestroyPlayer(&p1);
    DestroyPlayer(&p2);

    return 0;
}