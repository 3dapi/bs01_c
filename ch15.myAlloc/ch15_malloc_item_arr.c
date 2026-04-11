#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item
{
    char name[40];    // item name
    int type;
    int attack;
    int defence;
} Item;

int main(void)
{
    const int count = 3;
    const int item_size = sizeof(Item);
    const int buf_size = item_size * count;

    // Item 구조체 count개에 해당하는 연속 메모리 확보
    Item* items = (Item*)malloc(buf_size);
    if(items == NULL)
    {
        printf("malloc 실패\n");
        return 1;
    }

    // 구조체 모든 내용을 0으로 초기화. 문자열은 null 캐릭터로 채워짐
    memset(items, 0, buf_size);

    // 구조체 배열 초기화
    for(int i = 0; i < count; ++i)
    {
        memset(&items[i], 0, sizeof(Item));
        items[i].attack = 100;
        items[i].defence = 100;
    }

    // 첫 번째 아이템 설정
    strcpy(items[0].name, "Sword");
    items[0].type = 1;
    items[0].attack = 150;

    // 출력
    for(int i = 0; i < count; ++i)
    {
        printf("Item %d\n", i);
        printf(" name: %s\n", items[i].name);
        printf(" type: %d\n", items[i].type);
        printf(" attack: %d\n", items[i].attack);
        printf(" defence: %d\n", items[i].defence);
        printf("\n");
    }

    free(items);
    items = NULL;   // 해제 후 안전 처리

    return 0;
}
