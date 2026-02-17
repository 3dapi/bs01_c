#pragma once
#ifndef _AppData_H_
#define _AppData_H_

int InitData(void);
int SaveData(void);
int DestroyData(void);

typedef struct GAME_PLAY_RESULT
{
    char playedGame[40];
    int playedWin;
    char playedMessage[256];
} GAME_PLAY_RESULT;

// 가장 최근 게임 결과 가져오기.
const GAME_PLAY_RESULT* const GetRecentGamePlay(void);
// 게임 결과 기록.
int SaveRecentGamePlay(const GAME_PLAY_RESULT* playResult);

#endif // _AppData_H_