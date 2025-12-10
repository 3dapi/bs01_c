#include <stdio.h>

int main(void)
{
	while(1)
	{
		int choice = -999999;

		printf("\n=== 메뉴 ===\n");
		printf("1. 게임 시작\n");
		printf("2. 설정\n");
		printf("3. 종료\n");
		printf("번호를 선택하세요: ");
		scanf("%d", &choice);

		if(choice == 3)
			goto END_NORMAL;   // 정상 종료 지점으로 이동

		if(choice < 1 || choice > 3)
			goto END_ERROR;    // 비정상 종료 지점으로 이동

		// 1 또는 2를 선택한 경우 처리 코드가 들어갈 자리
		printf("선택: %d\n", choice);
	}

END_NORMAL:
	printf("프로그램을 종료합니다.\n");
	return 0;

END_ERROR:
	printf("잘못 선택된 메뉴입니다. 비정상 종료.\n");
	return 0;
}
