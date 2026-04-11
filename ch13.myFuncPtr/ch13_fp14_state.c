#include <stdio.h>

typedef enum {
    STATE_IDLE,
    STATE_MOVE,
    STATE_ATTACK
} State;

void Idle(void);
void Move(void);
void Attack(void);

void (*currentState)(void) = Idle;

void Idle(void)
{
    printf("Idle 상태\n");
    currentState = Move;    // 예시로 다음 상태로 변경
}

void Move(void)
{
    printf("Move 상태\n");
    currentState = Attack;
}

void Attack(void)
{
    printf("Attack 상태\n");
    currentState = Idle;
}

int main(void)
{
    for(int i = 0; i < 5; ++i) {
        currentState();     // 현재 상태의 함수 호출
    }
    return 0;
}