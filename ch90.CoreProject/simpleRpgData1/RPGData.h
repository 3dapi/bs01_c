#ifndef RPG_DATA_H
#define RPG_DATA_H

enum
{
    DATA_COUNT = 30,
};

// 캐릭터 기본 정보
extern int  characterId[DATA_COUNT];

// 클래스 / 장비
extern char classType[DATA_COUNT][3];
extern char equipmentType[DATA_COUNT][3];

// 능력치
extern int  attack[DATA_COUNT];       // 공격력
extern int  hp[DATA_COUNT];           // 체력

// 속성 / 지역
extern char tribe[DATA_COUNT][3];     // 종족
extern char startRegion[DATA_COUNT][3];
extern char targetRegion[DATA_COUNT][3];

// 기타 능력
extern int partySize[DATA_COUNT];     // 탑승인원
extern int travelDistance[DATA_COUNT];
extern int actionCount[DATA_COUNT];   // 월이용횟수

#endif
