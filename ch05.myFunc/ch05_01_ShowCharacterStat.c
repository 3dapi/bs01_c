#include <stdio.h>

void ShowCharacterStat(float playerHp, float playerMp)
{
	printf("Player Stat  ==============\n");
	printf("HP: %f\n", playerHp);
	printf("MP: %f\n", playerMp);
	// 함수 끝에 값이 없는 return; 은 의미 없지만 써도 상관 없다.
	return;
}

int main(void)
{
	// ShowCharacterStat 함수 호출.
	ShowCharacterStat(100.0F, 200.0F);
	return 0;
}