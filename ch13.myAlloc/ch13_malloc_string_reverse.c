#include <stdio.h>
#include <stdlib.h>    // malloc, free
#include <string.h>

int main(void)
{
	char input[1024];

	printf("문자열 입력: ");
	if(!fgets(input, sizeof(input), stdin))
	{
		printf("입력 오류\n");
		return 1;
	}

	// fgets는 개행 문자를 포함할 수 있으므로 제거
	input[strcspn(input, "\n")] = '\0';

	size_t len = strlen(input);

	// 문자열 길이 + 널 종료 문자('\0')를 저장할 공간까지 확보
	size_t buf_len = len + 1;

	// malloc은 단순히 buf_len 바이트의 연속된 메모리 공간을 확보한다.
	char* reversed = (char*)malloc(buf_len);
	if(!reversed)
	{
		printf("malloc 실패\n");
		return 1;
	}

	// 문자열 버퍼이므로 전체를 0으로 초기화하여 널 종료 상태를 보장
	memset(reversed, 0, buf_len);

	// 입력 문자열을 뒤에서부터 읽어 역순으로 저장
	for(size_t i = 0; i < len; ++i)
		reversed[i] = input[len - 1 - i];

	printf("역순 결과: %s\n", reversed);

	// 동적으로 확보한 메모리는 반드시 해제
	free(reversed);
	reversed = NULL;   // 해제 후 포인터 초기화

	return 0;
}