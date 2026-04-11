#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AppCommon.h"
#include "AppData.h"
#include "AppInput.h"
#include "GamePlayRockScissor.h"

// GamePlayRockScissor 초기화.
typedef struct GAME_PLAY_INFO
{
    int playedRound;
    int playRoundMax;
    int playRecent;            // 2: tie, 1: win, 0: lose -1: none
    int winPlayer;
    int winComputer;
    int tieResult;
} GAME_PLAY_INFO;

static GAME_PLAY_INFO g_playInfo;
// 게임 플레이 메뉴 함수.
static void DrawGamePlay(void);
// 게임 플레이 결과 메뉴 함수.
static void DrawGameResult(void);

// game play logic
// make computer's choice.
static int computerChoice = -1;

// GamePlayRockScissor 초기화.
int InitGamePlayRockScissor(void)
{
    printf("InitGamePlayRockScissor\n");
    memset(&g_playInfo, 0, sizeof(GAME_PLAY_INFO));
    g_playInfo.playRoundMax = 5;
    g_playInfo.playRecent = -1;
    return 0;
}

// GamePlayRockScissor 업데이트.
int UpdateGamePlayRockScissor(void)
{
    // check is game playing.
    if(3 > g_playInfo.winPlayer
        && g_playInfo.playedRound <= g_playInfo.playRoundMax)
    {
        // check input.
        if(GetKeyEvent('R') || GetKeyEvent('r'))
        {
            // restart game.
            InitGamePlayRockScissor();
            return 0;
        }
        else if(GetKeyEvent('Q') || GetKeyEvent('q'))
        {
            ChangeGameState(GAME_QUIT);
            return 0;
        }

        int playerChoice = -1;
        // player choice
        if     (GetKeyEvent('1'))
        {
            playerChoice = 1;       // rock
        }
        else if(GetKeyEvent('2'))
        {
            playerChoice = 2;       // scissor
        }
        else if(GetKeyEvent('3'))
        {
            playerChoice = 3;       // paper
        }

        // compare computer and player choice.
        if(computerChoice == 1)            // rock
        {
            if(playerChoice == 1)           // rock
            {
                ++g_playInfo.tieResult;
                g_playInfo.playRecent = 2;  // tie
            }
            else if(playerChoice == 3)
            {
                ++g_playInfo.winPlayer;
                g_playInfo.playRecent = 1;  // win
            }
            else                            // scissor 또는 다른 것 내면 지는 것으로 간주.
            {
                ++g_playInfo.winComputer;
                g_playInfo.playRecent = 0;  // lose
            }
        }
        else if(computerChoice == 2)       // scissor
        {
            if(playerChoice == 2)           // scissor
            {
                ++g_playInfo.tieResult;
                g_playInfo.playRecent = 2;  // tie
            }
            else if(playerChoice == 1)      // rock
            {
                ++g_playInfo.winPlayer;
                g_playInfo.playRecent = 1;  // win
            }
            else                            // paper 또는 다른 것 내면 지는 것으로 간주.
            {
                ++g_playInfo.winComputer;
                g_playInfo.playRecent = 0;  // lose
            }
        }
        else if(computerChoice == 3)       // paper
        {
            if(playerChoice == 3)           // paper
            {
                ++g_playInfo.tieResult;
                g_playInfo.playRecent = 2;  // tie
            }
            else if(playerChoice == 2)      // scissor
            {
                ++g_playInfo.winPlayer;
                g_playInfo.playRecent = 1;  // win
            }
            else                            // rock 또는 다른 것 내면 지는 것으로 간주.
            {
                ++g_playInfo.winComputer;
                g_playInfo.playRecent = 0;  // lose
            }
        }

        // 비김은 경기 횟수에 포함하지 않음.
        if(2 != g_playInfo.playRecent)
        {
            ++g_playInfo.playedRound;
        }
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

// GamePlayRockScissor 해제.
int DestroyGamePlayRockScissor(void)
{
    printf("DestroyGamePlayRockScissor\n");
    return 0;
}

// display for game play.
void DrawGamePlayRockScissor(void)
{
    if(    3 > g_playInfo.winPlayer
        && 3 > g_playInfo.winComputer
        && g_playInfo.playedRound < g_playInfo.playRoundMax)
    {
        // debugging 을 위해서 여기서 computer choice 를 선택.
        // game play logic: make computer's choice.
        computerChoice = 1+ rand() % 3; // 1, 2, or 3

        DrawGamePlay();
    }
    else
    {
        GAME_PLAY_RESULT playResult ={0,};
        strcpy(playResult.playedGame, "RockScissor");
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
    printf("        [가위바위보 게임]  (5판 3선승제)\n");
    printf("========================================================\n");
    printf("\n");
    printf("비김은 경기 판수에 반영 안함.\n");
    printf("진행: %d / %d 판\n", (g_playInfo.playedRound+1), g_playInfo.playRoundMax);
    printf("승패: %d 승  %d 패\n", g_playInfo.winPlayer, g_playInfo.winComputer);

    if    (2 == g_playInfo.playRecent)
    {
        printf("최근 결과: TIE\n");
    }
    else if(1 == g_playInfo.playRecent)
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
    printf("--------------------------------------------------------\n");
    printf("Computer: %d\n", computerChoice);
    printf("메뉴: [R] 재시작[Q] 게임 종료(로비)\n");
    printf("\n");
    printf("게임 플레이 선택: [1] 바위 [2] 가위  [3] 보\n");
    printf("\n");
}

void DrawGameResult(void)
{
    printf("\n");
    printf("========================================================\n");
    printf("        [가위바위보 게임 결과]  (5판 3선승제)\n");
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
