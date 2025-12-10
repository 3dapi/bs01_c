#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Player
{
	char name[32];
	int type;      // 1: Knight, 2: Sorcerer
	int attack;
	int hp;
} Player;

int main(void)
{
	int choice = 0;

	printf("직업을 선택하세요 (1: 기사, 2: 마법사): ");
	scanf("%d", &choice);

	Player* player = (Player*)malloc(sizeof(Player));
	if(!player)
	{
		printf("메모리 할당 실패\n");
		return 1;
	}
	memset(player, 0, sizeof(Player));

	if(1== choice)
	{
		strcpy(player->name, "Knight");
		player->type = 1;
		player->attack = 20;
		player->hp = 150;
	}
	else if(2 == choice)
	{
		strcpy(player->name, "Sorcerer");
		player->type = 2;
		player->attack = 35;
		player->hp = 80;
	}
	else
	{
		printf("잘못된 선택입니다.\n");
		free(player);
		player = NULL;
		return 1;
	}

	printf("\n생성된 캐릭터 정보\n");
	printf("이름: %s\n", player->name);
	printf("공격력: %d\n", player->attack);
	printf("체력: %d\n", player->hp);

	free(player);
	// 댕글링 포인터 방지
	player = NULL;
	return 0;
}