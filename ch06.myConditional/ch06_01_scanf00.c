#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    long long money = 0;
    scanf("%lld", &money);  // money 변수의 주소로 값을 입력받는다

    char name[8]= {0};
	scanf("%7s", name);     // name 배열에 7자리 문자를 입력받는다. 배열 이름은 배열의 첫 번째 요소의 주소를 나타내므로 name을 사용한다.

    printf("money: %lld - name: %s\n", money, name);

    return 0;
}
