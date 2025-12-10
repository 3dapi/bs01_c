#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Player
{
	char name[20];
	int level;
	int attack;
	int defense;
} Player;

void SavePlayerData(const char* fileName, const Player* player, int count);
int LoadPlayerData(const char* fileName, Player** player);

typedef struct Packet
{
	uint32_t size;
	uint8_t  data[];
} Packet;

int main(void)
{
	auto cc = sizeof(Packet);

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

void SavePlayerData(const char* fileName, const Player* player, int count)
{
	// 저장할 데이터가 없으면 저장하지 않음.
	if(!player || 0>=count)
	{
		printf("저장할 플레이어 데이터가 없습니다.\n");
		return;
	}
	// 저장 파일 열기.
	FILE* fp = fopen(fileName, "wb");
	if(!fp)
	{
		printf("저장 파일 %s 열기 실패\n", fileName);
		return;
	}

	// 플레이어 숫자 저장.
	fwrite(&count, sizeof(int), 1, fp);

	// 구조체 리스트 전체 저장.
	fwrite(player, sizeof(Player), count, fp);

	// 파일 닫기.
	fclose(fp);
}

int LoadPlayerData(const char* fileName, Player** player)
{
	*player = NULL; // 초기화
	// 저장 파일 열기.
	FILE* fp = fopen("player.dat", "rb");
	if(!fp)
	{
		printf("파일: %s 열기 실패\n", fileName);
		return -1;
	}
	
	// 플레이어 숫자 읽기.
	int player_count = 0;
	fread(&player_count, sizeof(int), 1, fp);
	if(0>=player_count)
	{
		printf("파일: %s에서 읽을 플레이어 데이터가 없습니다.\n", fileName);
		fclose(fp);
		return -1;
	}

	// 파일에서 읽어온 플레이어 데이터를 임시로 저장할 버퍼 동적 할당.
	Player* tmpPlayer = (Player*)malloc(sizeof(Player) * player_count);
	if (!tmpPlayer)
	{
		printf("메모리 생성 실패: %s\n", fileName);
		fclose(fp);
		return -1;
	}

	// 플레이어 데이터 통째로 로드.
	size_t readCount = fread(tmpPlayer, sizeof(Player), player_count, fp);
	fclose(fp);

	// 읽어온 데이터 개수가 원소 개수와 일치하는지 확인.
	if (readCount != player_count)
	{
		printf("파일: %s에서 플레이어 데이터를 읽는 중 오류 발생\n", fileName);
		free(tmpPlayer);
		return -1;
	}

	*player = tmpPlayer; // 읽어온 플레이어 데이터 버퍼 주소 전달.
	return player_count;
}
