#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AppCommon.h"
#include "AppData.h"
#include "AppInput.h"
#include "GamePlayUpDown.h"

typedef struct GAME_PLAY_INFO
{
    int playedRound;
    int playRoundMax;
    int playRecent;            // 1: win, 0: lose -1: none
    int winPlayer;
    int winComputer;
} GAME_PLAY_INFO;

static GAME_PLAY_INFO g_playInfo;
// 게임 플레이 메뉴 함수.
static void DrawGamePlay(void);
// 게임 플레이 결과 메뉴 함수.
static void DrawGameResult(void);

// 게임 플레이
typedef struct GAME_PLAY_NUMBER
{
    int computerChoice;
    int playerChoice;
    int playerTry;
} GAME_PLAY_NUMBER;
static GAME_PLAY_NUMBER g_playNumber;

void InitGamePlayNumber(void)
{
    // game play logic
    // make computer's choice.
    memset(&g_playNumber, 0, sizeof(GAME_PLAY_NUMBER));
    g_playNumber.computerChoice = 1 + rand() % 99; // [1, 99]
    g_playNumber.playerChoice = 0;
    g_playNumber.playerTry = 0;
}

// GamePlayUpDown 초기화.
int InitGamePlayUpDown(void)
{
    printf("InitGamePlayUpDown\n");
    memset(&g_playInfo, 0, sizeof(GAME_PLAY_INFO));
    g_playInfo.playRoundMax = 5;
    g_playInfo.playRecent = -1;
    // Init game play number.
    InitGamePlayNumber();
    return 0;
}

// GamePlayUpDown 업데이트.
int UpdateGamePlayUpDown(void)
{
    // check is game playing.
    if(3 > g_playInfo.winPlayer
        && g_playInfo.playedRound <= g_playInfo.playRoundMax)
    {
        // check input.
        if(GetKeyEvent('R') || GetKeyEvent('r'))
        {
            // restart game.
            InitGamePlayUpDown();
            return 0;
        }
        else if(GetKeyEvent('Q') || GetKeyEvent('q'))
        {
            ChangeGameState(GAME_QUIT);
            return 0;
        }

        g_playNumber.playerChoice= atoi(GetInputBuf());
        if(g_playNumber.computerChoice == g_playNumber.playerChoice)
        {
            ++g_playInfo.winPlayer;             // 플레이어 승
            g_playInfo.playRecent = 1;
            ++g_playInfo.playedRound;           // 판수 증가.
            g_playNumber.playerTry = 8;         // player try 초기화. 7번 이상으로 만들어서 다음 판으로 넘어가도록 함.
        }
        else
        {
            ++g_playNumber.playerTry;
            if(7<=g_playNumber.playerTry)
            {
                ++g_playInfo.winComputer;       // 컴퓨터 승
                ++g_playInfo.playedRound;       // 판수 증가.
            }
        }
    }

    if(3 <= g_playInfo.winPlayer
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

// GamePlayUpDown 해제.
int DestroyGamePlayUpDown(void)
{
    printf("DestroyGamePlayUpDown\n");
    return 0;
}

// display for game play.
void DrawGamePlayUpDown(void)
{
    if(3 > g_playInfo.winPlayer
        && 3 > g_playInfo.winComputer
        && g_playInfo.playedRound < g_playInfo.playRoundMax)
    {
        // debugging 을 위해서 여기서 computer choice 를 선택.
        if(7<=g_playNumber.playerTry)
        {
            InitGamePlayNumber();
        }
        DrawGamePlay();
    }
    else
    {
        GAME_PLAY_RESULT playResult ={0,};
        strcpy(playResult.playedGame, "UpDown");
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
    printf("        [UpDown 게임 숫자 맞추기]  (5판 3선승제)\n");
    printf("========================================================\n");
    printf("\n");
    printf("7번 안에 [1~99] 숫자 맞추기.\n");
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
    printf("--------------------------------------------------------\n");
    printf("Computer: %d\n", g_playNumber.computerChoice);
    printf("메뉴: [R] 재시작[Q] 게임 종료(로비)\n");
    printf("\n");
    if(0<g_playNumber.playerTry)
    {
        printf("플레이어 시도: %d\n", g_playNumber.playerTry);
        if(g_playNumber.computerChoice < g_playNumber.playerChoice)
        {
            printf("Up: ");
        }
        else if(g_playNumber.computerChoice > g_playNumber.playerChoice)
        {
            printf("Down: ");
        }
        printf("%d\n", g_playNumber.playerChoice);
    }
    printf("1~100 사이 숫자를 입력하시오.: ");
}

void DrawGameResult(void)
{
    printf("\n");
    printf("========================================================\n");
    printf("        [UpDown 게임 결과]  (5판 3선승제)\n");
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
