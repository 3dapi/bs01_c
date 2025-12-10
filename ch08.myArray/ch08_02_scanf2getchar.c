#include <stdio.h>
 
int main(void)
{
	char input_buf[20] = {0}; // 0으로 초기화 하면 모두 널 문자('\0')로 채워지는 것과 같다.

	// 한 글자씩 읽어서 배열에 저장
	for(int index = 0, ch = 0;(ch = getchar()) != '\n' && ch != EOF; ++index)
	{
		// 배열 크기를 넘지 않도록 마지막 한 칸은 널 문자용으로 남겨 둔다.
		if(index < sizeof(input_buf) - 1) // 19글자까지만 저장
			input_buf[index] = (char)ch;
	}
	printf("%s\n", input_buf);

	return 0;
}
