#include <stdio.h>

typedef struct Status
{
    int hp;
    int attack;
} Status;

typedef struct Position
{
    float x;
    float y;
} Position;

typedef struct Character
{
    char name[32];
    Status status;
    Position pos;
} Character;

void PrintCharacter(const Character* pCharacter);

int main(void)
{
    PrintCharacter(&(Character){ "Knight", 100, 15, 10.0f, 20.0f });

    struct Character hero = (Character){ "Mage", 60, 25, 5.0f, 8.0f };
    PrintCharacter(&hero);
    return 0;
 }

void PrintCharacter(const Character* pCharacter)
{
    printf("이름: %s, HP: %d, attack: %d\n"
            , pCharacter->name
            , pCharacter->status.hp
            , pCharacter->status.attack
        );
}
