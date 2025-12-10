#include <stdio.h>
#include <string.h>

int main(void)
{
	// 1) 문자열 리터럴과 배열의 차이
	char* p = "World";     // 읽기 전용 메모리
	char  s[] = "World";   // 배열 공간에 복사

	printf("초기 상태\n");
	printf("p  문자열: %s\n", p);
	printf("s  문자열: %s\n\n", s);

	// 문자열 리터럴 수정 시도 (위험 코드, 주석을 풀고 테스트해 볼 것)
	// p[0] = 'A';   // 많은 환경에서 런타임 오류 발생 가능

	// 배열은 수정 가능
	s[0] = 'A';
	printf("배열 s 수정 후 문자열: %s\n\n", s);

	// 2) sizeof vs strlen 차이 확인
	printf("sizeof(p) = %zu (포인터 크기)\n", sizeof(p));
	printf("sizeof(s) = %zu (배열 전체 크기)\n", sizeof(s));
	printf("strlen(p) = %zu (문자열 길이)\n", strlen(p));
	printf("strlen(s) = %zu (문자열 길이)\n\n", strlen(s));

	// 3) 문자열 복사 후 뒤집기
	char src[] = "Hello";
	char buf[32]={0};

	strcpy(buf, src);   // 문자열 복사
	int len = (int)strlen(buf);

	printf("원본 문자열: %s\n", buf);
	printf("역순 출력   : ");
	for(int i = len - 1; i >= 0; --i)
	{
		printf("%c", buf[i]);
	}

	printf("\n\n");
	
	// 4) 문자열 리터럴 풀 확인 (주소 비교)
	char* a = "Hi";
	char* b = "Hi";

	printf("문자열 리터럴 풀 테스트\n");
	printf("a 주소: %p\n", a);
	printf("b 주소: %p\n", b);
	if(a == b)
		printf("a와 b는 같은 문자열 리터럴을 가리킨다.\n");
	else
		printf("a와 b는 다른 위치를 가리킨다.\n");

	return 0;
}
