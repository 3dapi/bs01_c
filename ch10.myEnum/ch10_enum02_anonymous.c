#include <stdio.h>

enum
{
    MAX_LEVEL = 99,
    MAX_SKILLS = 10,
    INVENTORY_SLOTS = 30
};

#define DEFINE_MAX_BACKPACK 6
const static int CONST_MAX_ITEMS = 500;


int main(void)
{
    int skillLevels[MAX_SKILLS];    // 컴파일 타임 상수.
    int inventory[INVENTORY_SLOTS];

    int backPack[DEFINE_MAX_BACKPACK] = {0};
    //int itemList[CONST_MAX_ITEMS];  // CONST_MAX_ITEMS는 컴파일 타임 상수가 아니므로 에러 발생. C++에서는 허용됨.

    return 0;
}
