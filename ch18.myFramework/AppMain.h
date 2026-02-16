#pragma once
#ifndef _AppMain_H_
#define _AppMain_H_

typedef enum GAME_STATE
{
	GAME_NONE			= 0,
	GAME_BEGIN			= 10,
	GAME_PLAY_ODD_EVEN,
	GAME_NUMBER_BASEBALL,
} GAME_STATE;

int AppInit(void);
int AppRun(void);

#endif // _AppMain_H_