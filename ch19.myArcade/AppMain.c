#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "AppCommon.h"
#include "AppData.h"
#include "AppInput.h"
#include "GameLobby.h"
#include "GameResult.h"
#include "GamePlayOddEven.h"
#include "GamePlayUpDown.h"
#include "GamePlayRockScissor.h"

static EGAME_STATE g_gameStateCur = GAME_LOBBY;
static EGAME_STATE g_gameStateOld = GAME_LOBBY;
static void CheckGameState(void);

// 시스템 초기화
int AppInit(void)
{
    printf("AppInit\n");
    srand((unsigned int)time(NULL));

    if(0>InitData())
        return -1;
    if(0>InitInput())
        return -1;

    if(0>InitGameLobby())
        return -1;
    return 0;
}

// 시스템 자원 해제
int AppDestroy(void)
{
    printf("AppDestroy\n");
    DestroyGameLobby();
    DestroyGamePlayOddEven();
    DestroyGamePlayUpDown();
    DestroyGamePlayRockScissor();
    DestroyGameResult();

    DestroyInput();
    DestroyData();
    return 0;
}

int AppRun(void)
{
    int hr = 0;
    printf("AppRun\n");

    while(1)
    {
        if(GAME_QUIT == g_gameStateCur)
            break;

        system("cls");
        CheckGameState();

        // draw
        switch(g_gameStateCur)
        {
            case GAME_LOBBY:
                DrawGameLobby();
                break;
            case GAME_PLAY_ODD_EVEN:
                DrawGamePlayOddEven();
                break;
            case GAME_PLAY_UP_DOWN:
                DrawGamePlayUpDown();
                break;
            case GAME_PLAY_ROCK_SCISSOR:
                DrawGamePlayRockScissor();
                break;
            case GAME_RESULT:
                DrawGameResult();
                break;
        }

        // update input
        if(0>(hr = UpdateInput()))
            break;

        // update play
        switch(g_gameStateCur)
        {
            case GAME_LOBBY:
                hr = UpdateGameLobby();
                break;
            case GAME_PLAY_ODD_EVEN:
                hr = UpdateGamePlayOddEven();
                break;
            case GAME_PLAY_UP_DOWN:
                hr = UpdateGamePlayUpDown();
                break;
            case GAME_PLAY_ROCK_SCISSOR:
                hr = UpdateGamePlayRockScissor();
                break;
            case GAME_RESULT:
                hr = UpdateGameResult();
                break;
        }
        if(0>hr)
            break;
    }
    // hr 처리.
    // ...
    // AppInit 관련 해제.
    AppDestroy();
    return 0;
}

// 상태 머신 변경
void ChangeGameState(EGAME_STATE newGameState)
{
    g_gameStateCur = newGameState;
}
// 상태 머신이 변경되면 이전 상태 머신에서 사용한 게임 로직은 삭제
void CheckGameState(void)
{
    if(g_gameStateCur != g_gameStateOld)
    {
        switch(g_gameStateOld)
        {
            case GAME_LOBBY:
                DestroyGameLobby();
                break;
            case GAME_PLAY_ODD_EVEN:
                DestroyGamePlayOddEven();
                break;
            case GAME_PLAY_UP_DOWN:
                DestroyGamePlayUpDown();
                break;
            case GAME_PLAY_ROCK_SCISSOR:
                DestroyGamePlayRockScissor();
                break;
            case GAME_RESULT:
                DestroyGameResult();
                break;
        }
        switch(g_gameStateCur)
        {
            case GAME_LOBBY:
                InitGameLobby();
                break;
            case GAME_PLAY_ODD_EVEN:
                InitGamePlayOddEven();
                break;
            case GAME_PLAY_UP_DOWN:
                InitGamePlayUpDown();
                break;
            case GAME_PLAY_ROCK_SCISSOR:
                InitGamePlayRockScissor();
                break;
            case GAME_RESULT:
                InitGameResult();
                break;
        }
        g_gameStateOld = g_gameStateCur;
    }
}
