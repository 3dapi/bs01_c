#include <stdio.h>
#include <string.h>
#include "AppCommon.h"
#include "AppData.h"
#include "AppInput.h"
#include "GameResult.h"

// GameResult 초기화.
int InitGameResult(void)
{
    printf("InitGameResult\n");
    return 0;
}

// GameResult 업데이트.
int UpdateGameResult(void)
{
    if     (GetKeyEvent('L') || GetKeyEvent('l'))
    {
        ChangeGameState(GAME_LOBBY);
    }
    else if(GetKeyEvent('Q') || GetKeyEvent('q'))
    {
        ChangeGameState(GAME_QUIT);
    }
    return 0;
}

// GameResult 해제.
int DestroyGameResult(void)
{
    printf("DestroyGameResult\n");
    return 0;
}

void DrawGameResult(void)
{
    const GAME_PLAY_RESULT* playedResult = GetRecentGamePlay();

    printf("\n");
    printf("========================================================\n");
    printf("        [게임 결과]\n");
    printf("========================================================\n");
    printf("\n");
    printf("게임: %s\n", playedResult->playedGame);
    printf("결과: %s\n", playedResult->playedWin? "WIN" : "LOSE");
    printf("\n--------------------------------------------------------\n\n");
    printf("메뉴: [L] 로비로 이동     [Q] 종료\n");
    printf("\n--------------------------------------------------------\n");
}
