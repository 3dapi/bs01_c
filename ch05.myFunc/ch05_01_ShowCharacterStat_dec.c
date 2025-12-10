#include <stdio.h>

// main 함수가 ShowCharacterStat 함수를 호출하므로,
// 먼저 함수 선언을 main 함수보다 앞에 작성한다.
void ShowCharacterStat(float playerHp, float playerMp);

int main(void)
{
	// ShowCharacterStat 함수 호출
	ShowCharacterStat(100.0F, 200.0F);
	return 0;
}

// 함수 정의는 코드에서 어느 위치에 있어도 상관없다.
void ShowCharacterStat(float playerHp, float playerMp)
{
	printf("Player Stat  ==============\n");
	printf("HP: %f\n", playerHp);
	printf("MP: %f\n", playerMp);

	// 반환값이 없으므로 return;은 생략 가능하지만 작성해도 무방하다.
	return;
}