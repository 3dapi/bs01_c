#include <stdio.h>

int mayScanf(char buf[], int bufsize);

int main(void)
{
	char input_buf[20] = {0}; // 0으로 초기화 널 문자('\0')로 채움.

	mayScanf(input_buf, sizeof(input_buf));

	printf("%s\n", input_buf);

	return 0;
}

int mayScanf(char buf[], int bufsize)
{
	int read_count = 0; // 읽은 문자 개수.
	int index = 0;		// 배열 마지막에 널문자 추가하기 위해 밖으로 뺌.

	// 한 글자씩 읽어서 배열에 저장
	for(int ch = 0;(ch = getchar()) != '\n' && ch != EOF; ++index)
	{
		// 배열 크기를 넘지 않도록 마지막 한 칸은 널 문자용으로 남겨 둔다.
		if(index < bufsize - 1) // 버퍼 크기 전까지만 저장.
		{
			buf[index] = (char)ch;
			++read_count;
		}
	}
	// 문자열 종료 보장
	buf[index] = '\0';
	// 읽은 문자를 반환.
	return read_count;
}
