#include <stdio.h>

enum CharacterState
{
    STATE_IDLE,
    STATE_MOVE,
    STATE_ATTACK,
    STATE_DEATH
};

// typedef로 열거형의 별칭 생성
typedef enum CharacterState CharacterState;

//typedef enum MyCharacterState
//{
//	STATE_IDLE,
//	STATE_MOVE,
//	STATE_ATTACK,
//	STATE_DEATH
//} MyCharacterState, OtherCharacterState;

int main(void)
{
    CharacterState state = STATE_IDLE;

    return 0;
}
