#pragma once
#ifndef _AppCommon_H_
#define _AppCommon_H_

typedef enum EGAME_STATE
{
    GAME_NONE               = 0x00,
    GAME_QUIT               = 0x01,
    GAME_LOBBY              = 0x10,
    GAME_PLAY_ODD_EVEN      ,
    GAME_PLAY_UP_DOWN       ,
    GAME_PLAY_ROCK_SCISSOR  ,
    GAME_RESULT             = 0x40,
} EGAME_STATE;

void ChangeGameState(EGAME_STATE newGameState);

#endif // _AppCommon_H_
