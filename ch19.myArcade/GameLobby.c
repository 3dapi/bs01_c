#include <stdio.h>
#include <string.h>
#include "AppCommon.h"
#include "AppInput.h"
#include "GameLobby.h"

// GameLobby 초기화.
int InitGameLobby(void)
{
    printf("InitGameLobby\n");
    return 0;
}

// GameLobby 업데이트.
int UpdateGameLobby(void)
{
    if(GetKeyEvent('1'))
    {
        ChangeGameState(GAME_PLAY_ODD_EVEN);
    }
    else if(GetKeyEvent('2'))
    {
        ChangeGameState(GAME_PLAY_UP_DOWN);
    }
    else if(GetKeyEvent('3'))
    {
        ChangeGameState(GAME_PLAY_ROCK_SCISSOR);
    }
    else if(GetKeyEvent('Q') || GetKeyEvent('q'))
    {
        ChangeGameState(GAME_QUIT);
    }

    return 0;
}

// GameLobby 해제.
int DestroyGameLobby(void)
{
    printf("DestroyGameLobby\n");
    return 0;
}

void DrawGameLobby(void)
{
    printf("\n");
    printf("========================================================\n");
    printf("    오  락  실\n");
    printf("========================================================\n\n");
    printf("    1. 홀짝 게임\n");
    printf("    2. Up/Down 게임\n");
    printf("    3. 가위바위보\n\n");
    printf("    Q. 종료\n\n");
    printf("--------------------------------------------------------\n");
}
