#include <stdio.h>
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
		system("cls");
		CheckGameState();

		// draw menu
		switch(g_gameStateCur)
		{
			case GAME_LOBBY:
				MenuGameLobby();
				break;
			case GAME_PLAY_ODD_EVEN:
				MenuGamePlayOddEven();
				break;
			case GAME_PLAY_UP_DOWN:
				MenuGamePlayUpDown();
				break;
			case GAME_PLAY_ROCK_SCISSOR:
				MenuGamePlayRockScissor();
				break;
			case GAME_RESULT:
				MenuGameResult();
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

void ChangeGameState(EGAME_STATE newGameState)
{
	g_gameStateCur = newGameState;
}

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
