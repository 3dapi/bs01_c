#include <stdio.h>

int main(void)
{
	char ch0='A',ch1=66;
	int number1,number2;
	int number3=1111;
	int number4=2222;
	printf("ch0: %d, ch0: %c \n",ch0,ch0);
	printf("ch1: %d, ch1: %c \n",ch1,ch1);

	// 최신 컴파일러에서는 초기화 안하면 컴파일 에러가 발생하나,
	// 오래된 컴파일러는 문제 없이 넘어감
	//printf("number1: %d, number2: %d \n",number1,number2);

	number1=6666;
	number2=7777;

	printf("number1: %d, number2: %d \n",number1,number2);
	printf("number3: %d, number4: %d \n",number3,number4);

	return 0;
}