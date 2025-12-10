#include <stdio.h>

static void Counter(void);   // 파일 내부 전용 함수

int main(void)
{
	Counter();  // 출력: count = 1
	Counter();  // 출력: count = 2
	Counter();  // 출력: count = 3
	return 0;
}

// static 함수는 선언부에만 static 을 붙여도 된다.
void Counter(void)
{
	static int count = 0;  // static 지역 변수: 한 번만 초기화
	count++;
	printf("count = %d\n", count);
}
