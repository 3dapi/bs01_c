#include <stdio.h>

typedef struct Player
{
    char name[20];
    int level;
    int attack;
    int defense;
} Player;

int SavePlayerData(const char* fileName, const Player* player, int count);
int LoadPlayerData(const char* fileName, Player** player);

int main(void)
{
    Player player_src[] =
    {
        {"Knight", 10, 25, 15},
        {"Archer", 8, 18, 10},
        {"Wizard", 12, 30, 5},
        {"Paladin", 15, 28, 22},
        {"Assassin", 9, 35, 8},
        {"Berserker", 14, 40, 12},
        {"Ranger", 11, 22, 14},
        {"Cleric", 13, 16, 25},
        {"Necromancer", 17, 34, 9},
        {"Monk", 10, 20, 18},
        {"Templar", 16, 27, 30},
        {"Druid", 12, 19, 17}
    };

    // 원본 플레이어 데이터를 바이너리 파일로 저장.
    int player_count = sizeof(player_src)/sizeof(player_src[0]);
    SavePlayerData("player.dat", player_src, player_count);

    // 파일에 저장된 플레이어 데이터 읽기.
    Player* dest_buf = NULL;
    int dest_count = LoadPlayerData("player.dat", &dest_buf);

    // 읽어온 플레이어 데이터 출력.
    printf("이름\t\t\t레벨\t공격력\t방어력\n");
    for(int i=0; i<dest_count; ++i)
    {
        Player* ptr = &dest_buf[i];
        printf("%19s\t%4d\t%4d\t%4d\n"
            , ptr->name, ptr->level, ptr->attack, ptr->defense);
    }

    // 동적 할당된 버퍼 해제.
    if(dest_buf)
    {
        free(dest_buf);
        dest_buf = NULL;
    }
    return 0;
}

int SavePlayerData(const char* fileName, const Player* player, int count)
{
    FILE* fp = NULL;    // 저장 파일 포인터.

    // 저장할 데이터가 없으면 저장하지 않음.
    if(!player || 0>=count)
    {
        printf("저장할 플레이어 데이터가 없습니다.\n");
        goto ERR_HANDLE;
    }
    // 1. 저장 파일 열기.
    fp = fopen(fileName, "wb");
    if(!fp)
    {
        printf("저장 파일 %s 열기 실패\n", fileName);
        goto ERR_HANDLE;
    }

    // 2. 플레이어 숫자 저장.
    if(1 != fwrite(&count, sizeof(int), 1, fp))
    {
        goto ERR_HANDLE;
    }
    // 3. 구조체 리스트 전체 저장.
    if(count != (int)fwrite(player, sizeof(Player), count, fp))
    {
        goto ERR_HANDLE;
    }

    // 파일 닫기.
    fclose(fp);
    return count;
ERR_HANDLE:
    if(fp)
        fclose(fp);
    return -1;
}

int LoadPlayerData(const char* fileName, Player** player)
{
    *player = NULL;             // player 초기화.
    int player_count = 0;       // player 숫자.
    Player* tmpPlayer = NULL;   // 파일에서 읽어올 플레이어 데이터를 임시로 저장할 버퍼.
    size_t readCount = 0;       // 파일에서 읽어올 플레이어 데이터 숫자.

    // 1. 저장 파일 열기.
    FILE* fp = fopen(fileName, "rb");
    if(!fp)
    {
        printf("파일: %s 열기 실패\n", fileName);
        goto ERR_HANDLE;
    }

    // 2. 플레이어 숫자 읽기.
    if(1 != fread(&player_count, sizeof(int), 1, fp))
    {
        printf("파일: %s에서 플레이어 수 읽기 실패\n", fileName);
        goto ERR_HANDLE;
    }
    if(0>=player_count)
    {
        printf("파일: %s에서 읽을 플레이어 데이터가 없습니다.\n", fileName);
        goto ERR_HANDLE;
    }

    // 3. 파일에서 읽어온 플레이어 데이터를 임시로 저장할 버퍼 동적 할당.
    tmpPlayer = malloc(sizeof(Player) * player_count);
    if (!tmpPlayer)
    {
        printf("메모리 생성 실패: %s\n", fileName);
        goto ERR_HANDLE;
    }

    // 4. 플레이어 데이터 통째로 로드.
    readCount = fread(tmpPlayer, sizeof(Player), player_count, fp);

    // 5. 읽어온 데이터 개수가 원소 개수와 일치하는지 확인.
    if (readCount != (size_t)player_count)
    {
        printf("파일: %s에서 플레이어 데이터를 읽는 중 오류 발생\n", fileName);
        goto ERR_HANDLE;
    }

    //6. 읽어온 플레이어 데이터 버퍼 주소 전달.
    *player = tmpPlayer;
    fclose(fp);
    return player_count;

ERR_HANDLE:
    if(fp)
        fclose(fp);
    if(tmpPlayer)
        free(tmpPlayer);
    return -1;
}
