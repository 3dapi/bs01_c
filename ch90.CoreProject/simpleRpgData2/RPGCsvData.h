#ifndef RPG_CSV_DATA_H
#define RPG_CSV_DATA_H

/*
    CSV 문자열 배열은 마지막 빈 문자열("")을 만날 때까지 유효한 데이터로 처리한다.
    배열의 전체 개수는 while 문으로 직접 계산한다.

    characterCsv는 캐릭터 기본 정보와 캐릭터 게임 정보를 하나로 합친 단일 캐릭터 데이터이다.
    itemCsv는 아이템 데이터이며, characterCsv의 ITEM_ID와 연결하여 사용할 수 있다.
*/

extern const char* characterCsv[];
extern const char* itemCsv[];

#endif
