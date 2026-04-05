#include <stdio.h>

struct Character {
    char name[32];
    int hp;
};

int main(void)
{
    struct Character party[3] = {
        { "Knight", 100 },
        { "Archer",  80 },
        { "Mage",    60 }
    };

    struct Character* ptr = party;  // &party[0]

    printf("=== 배열 방식 ===\n");
    for (int i = 0; i < 3; ++i)
        printf("%s : %d HP\n", party[i].name, party[i].hp);

    printf("\n=== 포인터 방식 ===\n");
    for (int i = 0; i < 3; ++i)
        printf("%s : %d HP\n", (ptr + i)->name, (ptr + i)->hp);

    return 0;
}
