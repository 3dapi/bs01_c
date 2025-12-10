#include <stdio.h>

int main(void)
{
	// 문자열을 안 배웠지만 미리 알아 둔다.
	char player_name[64]= {0, };
	int  player_level = -999999;
	int  player_hp = -999999;
	long long player_gold = -999999;

	printf("플레이어 이름을 입력하세요 :");
	scanf("%s", player_name);
	
	printf("플레이어 레벨을 입력하세요:");
	scanf("%d", &player_level);

	printf("플레이어 체력을 입력하세요 :");
	scanf("%d", &player_hp);

	printf("플레이어 체력을 입력하세요 :");
	scanf("%lld", &player_gold);

	printf("========================\n");
	printf("플레이어 정보\n");
	printf("이름: %s\n", player_name);
	printf("레벨: %d\n", player_level);
	printf("체력: %d\n", player_hp);
	printf("골드: %lld\n", player_gold);

	return 0;
}