#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AppCommon.h"
#include "AppData.h"
#include "AppInput.h"
#include "GamePlayOddEven.h"

typedef struct GAME_PLAY_INFO
{
    int playedRound;
    int playRoundMax;
    int playRecent;            // 1: win, 0: lose -1: none
    int winPlayer;
    int winComputer;
} GAME_PLAY_INFO;

static GAME_PLAY_INFO g_playInfo;
static int computerChoice = -1;

// 게임 플레이 메뉴 함수.
static void DrawGamePlay(void);
// 게임 플레이 결과 메뉴 함수.
static void DrawGameResult(void);

// GamePlayOddEven 초기화.
int InitGamePlayOddEven(void)
{
    printf("InitGamePlayOddEven\n");
    memset(&g_playInfo, 0, sizeof(GAME_PLAY_INFO));
    g_playInfo.playRoundMax = 5;
    g_playInfo.playRecent = -1;
    return 0;
}

// GamePlayOddEven 업데이트.
int UpdateGamePlayOddEven(void)
{
    // check is game playing.
    if(3 > g_playInfo.winPlayer
        && g_playInfo.playedRound <= g_playInfo.playRoundMax)
    {
        // check input.
        if(GetKeyEvent('R') || GetKeyEvent('r'))
        {
            // restart game.
            InitGamePlayOddEven();
            return 0;
        }
        else if(GetKeyEvent('Q') || GetKeyEvent('q'))
        {
            ChangeGameState(GAME_QUIT);
            return 0;
        }

        int playerChoice = -1;
        // player choice
        if(GetKeyEvent('O') || GetKeyEvent('o'))
        {
            playerChoice = 1; // odd
        }
        else if(GetKeyEvent('E') || GetKeyEvent('e'))
        {
            playerChoice = 0; // even
        }

        if(computerChoice == playerChoice)
        {
            ++g_playInfo.winPlayer;
            g_playInfo.playRecent = 1;
        }
        else
        {
            ++g_playInfo.winComputer;
            g_playInfo.playRecent = 0;
        }

        ++g_playInfo.playedRound;
    }

    if(    3 <= g_playInfo.winPlayer
        || 3 <= g_playInfo.winComputer
        || g_playInfo.playedRound >= g_playInfo.playRoundMax)
    {
        // 게임 결과 창 이동.
        if(GetKeyEvent('N') || GetKeyEvent('n'))
        {
            ChangeGameState(GAME_RESULT);
        }
    }

    return 0;
}

// GamePlayOddEven 해제.
int DestroyGamePlayOddEven(void)
{
    printf("DestroyGamePlayOddEven\n");
    return 0;
}

// display for game play.
void DrawGamePlayOddEven(void)
{
    if(    3 > g_playInfo.winPlayer
        && 3 > g_playInfo.winComputer
        && g_playInfo.playedRound < g_playInfo.playRoundMax)
    {
        // game play logic
        // make the computer's choice.
        computerChoice = rand() % 2; // 0 or 1
        DrawGamePlay();
    }
    else
    {
        GAME_PLAY_RESULT playResult ={0,};
        strcpy(playResult.playedGame, "OddEven");
        playResult.playedWin  = (g_playInfo.winComputer < g_playInfo.winPlayer) ? 1 : 0;
        strcpy(playResult.playedMessage, (g_playInfo.winComputer < g_playInfo.winPlayer) ? "WIN" : "LOSE");
        SaveRecentGamePlay(&playResult);
        DrawGameResult();
    }
}

void DrawGamePlay(void)
{
    printf("\n");
    printf("========================================================\n");
    printf("        [홀짝 게임]  (5판 3선승제)\n");
    printf("========================================================\n");
    printf("\n");
    printf("진행: %d / %d 판\n", (g_playInfo.playedRound+1), g_playInfo.playRoundMax);
    printf("승패: %d 승  %d 패\n", g_playInfo.winPlayer, g_playInfo.winComputer);

    if(1 == g_playInfo.playRecent)
    {
        printf("최근 결과: WIN\n");
    }
    else if(0 == g_playInfo.playRecent)
    {
        printf("최근 결과: LOSE\n");
    }
    else
    {
        printf("최근 결과: -\n");
    }
    printf("Computer: %d\n", computerChoice);
    printf("--------------------------------------------------------\n");
    printf("메뉴: [R] 재시작[Q] 게임 종료(로비)\n");
    printf("\n");
    printf("게임 플레이 선택: [O] 홀 [E] 짝\n");
    printf("\n");
}

void DrawGameResult(void)
{
    printf("\n");
    printf("========================================================\n");
    printf("        [홀짝 게임 결과]  (5판 3선승제)\n");
    printf("========================================================\n");
    printf("\n");
    printf("진행: %d / %d 판\n", g_playInfo.playedRound, g_playInfo.playRoundMax);
    printf("결과: %d 승  %d 패\n", g_playInfo.winPlayer, g_playInfo.winComputer);
    printf("\n");
    if(g_playInfo.winComputer< g_playInfo.winPlayer)
        printf("You Win !!!\n\n");
    else
        printf("You Lose !!!\n\n");
    printf("--------------------------------------------------------\n");
    printf("게임 결과화면 이동: [N]\n");
    printf("\n");
}
