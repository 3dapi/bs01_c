#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "AppData.h"

typedef struct Data
{
    int gameData;
}Data;

static Data g_Data;
static GAME_PLAY_RESULT g_playResult;

// 게임 데이터 초기화.
int InitData(void)
{
    printf("InitData\n");
    return 0;
}

// 게임 데이터 저장.
int SaveData(void)
{
    printf("SaveData\n");
    return 0;
}

// 게임 데이터 해제.
int DestroyData(void)
{
    printf("DestroyData\n");
    return 0;
}

const GAME_PLAY_RESULT* const GetRecentGamePlay(void)
{
    return &g_playResult;
}

int SaveRecentGamePlay(const GAME_PLAY_RESULT* playResult)
{
    if(!playResult)
    {
        printf("Invalid data.\n");
        return -1;
    }
    memcpy(&g_playResult, playResult, sizeof(GAME_PLAY_RESULT));
    FILE* fp = fopen("GameResult.txt", "a");
    if(fp)
    {
        time_t time_tt = time(NULL);    // 현재 시각을 초 단위로 얻기
        struct tm* tm_tt = localtime(&time_tt); // 포맷 변환을 위해 구조체로 변환
        // 형식에 맞춰 출력
        char time_buf[20];
        strftime(time_buf, sizeof(time_buf), "%F_%H:%M:%S", tm_tt); // "YYYY-mm-dd_HH:MM:SS
        // 날짜, 시간 기록.
        fprintf(fp, "%s\t", time_buf);
        // 게임 이름
        fprintf(fp, "%s\t", playResult->playedGame);
        // 메시지 기록
        fprintf(fp, "%s\n", playResult->playedMessage);
        fclose(fp);
        return 0;
    }
    printf("Failed to open file.\n");
    return -1;
}
