#include <stdio.h>

typedef enum CharacterState
{
    STATE_IDLE,     // 대기
    STATE_MOVE,     // 이동
    STATE_ATTACK,   // 공격
    STATE_HIT,      // 피격
    STATE_DEATH     // 사망
} CharacterState;

//사용 예:
CharacterState state = STATE_IDLE;

void ChangeState(CharacterState newState)
{
    state = newState;
}


typedef enum ResultCode
{
    RESULT_OK,            // 성공
    RESULT_ERROR_FILE,    // 파일 에러
    RESULT_ERROR_MEMORY,  // 메모리 부족
    RESULT_ERROR_UNKNOWN  // 알 수 없는 에러
} ResultCode;

ResultCode LoadData(const char* filename)
{
    // 파일을 열고 데이터를 읽는다고 가정
    // 상황에 맞게 적절한 코드 반환
    return RESULT_OK;
}

void UpdateCharacter(CharacterState state)
{
    switch (state)
    {
    case STATE_IDLE:
        printf("캐릭터가 가만히 서 있습니다.\n");
        break;
    case STATE_MOVE:
        printf("캐릭터가 이동 중입니다.\n");
        break;
    case STATE_ATTACK:
        printf("캐릭터가 공격합니다!\n");
        break;
    case STATE_DEATH:
        printf("캐릭터가 쓰러졌습니다.\n");
        break;
    default:
        printf("알 수 없는 상태입니다.\n");
        break;
    }
}

int main(void)
{
    CharacterState state = STATE_IDLE;

    return 0;
}
