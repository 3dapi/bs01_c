#include <stdio.h>
 
int main(void)
{
	// 문자 입력 받기
	char ch=0;
	printf("문자 하나를 입력하세요: ");
	scanf("%c", &ch);
	printf("입력한 문자는 \"%c\" 입니다.\n", ch);
 
	// int 형 입력 받기
	int age=0;
	printf("나이를 입력하세요: ");
	scanf("%d", &age);
	printf("당신의 나이는 %d 세입니다.\n", age);
 
	// long long 형 입력 받기
	long long money=0;
	printf("금액을 입력하세요: ");
	scanf("%lld", &money);
	printf("입력한 금액은 %lld 원 입니다.\n", money);
 
	return 0;
}
