#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ItemInfo
{
    char id[16];
    char name[60];
    char description[120];
    char itemtype[32];
    char rarity[32];
    int price;
    float weight;
} ItemInfo;

int main(void)
{
    FILE* fp = fopen("item_info.csv", "r");
    if(!fp)
    {
        printf("파일 열기 실패\n");
        return 1;
    }

    char buffer[512];

    if(!fgets(buffer, sizeof(buffer), fp))
    {
        fclose(fp);
        return 1;
    }
    int itemCount=0;
    int result = sscanf(buffer, "%*s %d", &itemCount);

    // 헤더 스킵.
    if(!fgets(buffer, sizeof(buffer), fp))
    {
        fclose(fp);
        return 1;
    }

    // 타입 라인 스킵.
    if(!fgets(buffer, sizeof(buffer), fp))
    {
        fclose(fp);
        return 1;
    }

    // 아이템 정보 저장할 공간 확보.
    ItemInfo* itemList = (ItemInfo*) malloc(sizeof(ItemInfo) * itemCount);
    if(!itemList)
    {
        fclose(fp);
        return 1;
    }
    memset(itemList, 0, sizeof(ItemInfo) * itemCount);

    int itemIndex = 0;
    while(1)
    {
        char* ptr = fgets(buffer, sizeof(buffer), fp);
        if(!ptr)
            break;

        if(itemIndex >= itemCount)
            break;
        // 아이템이 비어 있으면 빈곳이면 더이상 데이터가 없음을 인식하고 
        if(4 >= strlen(buffer))
            break;

        // 아이템 정보 파싱.
        ItemInfo* pItem = &itemList[itemIndex];
        if(sscanf(buffer
            , "%15[^,],%59[^,],%119[^,],%31[^,],%31[^,],%d,%f"
            , pItem->id
            , pItem->name
            , pItem->description
            , pItem->itemtype
            , pItem->rarity
            , &pItem->price
            , &pItem->weight) == 7)
        {
            ++itemIndex;
        }
    }
    // csv 파일 닫기.
    fclose(fp);

    // item 정보 출력.
    for(int i = 0; i < itemIndex; ++i)
    {
        ItemInfo* pItem = &itemList[i];
        printf("[%s] (%s / %s) 가격:%d 무게:%.1f  %s  %s\n"
        , pItem->id
        , pItem->itemtype
        , pItem->rarity
        , pItem->price
        , pItem->weight
        , pItem->name
        , pItem->description);
    }

    free(itemList);
    itemList = NULL;
    return 0;
}
