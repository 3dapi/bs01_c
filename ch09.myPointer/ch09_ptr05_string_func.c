#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("=== 1. strlen ===\n");
	char* str = "Hello";
	size_t len= strlen(str);
	printf("문자열: %s ==> length: %zu\n", str, len);

	printf("=== 2. strcpy / strncpy ===\n");
	char src[] = "C Language";
	char dst[32];
	strcpy(dst, src);
	printf("strcpy(dst, src) → %s\n", dst);

	char dst2[8];
	strncpy(dst2, src, sizeof(dst2));
	dst2[sizeof(dst2) - 1] = '\0';        // 널 종료 보장

	char str_buf[8]={0};                  // 모든 요소를 '\0'으로 초기화.
	strncpy(str_buf, src, sizeof(str_buf)-1);  // 마지막 한 칸을 널 문자를 위해 비워 둔다.
	printf("strncpy(str_buf, src, 7) → %s\n\n", str_buf);
		
	printf("=== 3. strcmp / strncmp ===\n");
	printf("strcmp(\"apple\", \"banana\") = %d\n", strcmp("apple", "banana"));
	printf("strcmp(\"same\", \"same\") = %d\n", strcmp("same", "same"));
	printf("strncmp(\"abcdef\", \"abcxyz\", 3) = %d\n\n",
		   strncmp("abcdef", "abcxyz", 3));

	printf("=== 4. strcat / strncat ===\n");
	char buf[32] = "Hello";
	strcat(buf, " World");
	printf("strcat → %s\n", buf);

	strncat(buf, "!!!***", 3);  // "!!!"까지만 붙이기
	printf("strncat 3글자 → %s\n\n", buf);

	printf("=== 5. strchr ===\n");
	char text[] = "Hello World";
	char* p = strchr(text, 'o');
	if(p != NULL)
	{
		printf("문자 'o'를 처음 찾은 위치부터: %s\n", p);
	}
	else
	{
		printf("문자 'o'를 찾지 못했습니다.\n");
	}
	printf("\n");

	printf("=== 6. strstr ===\n");
	char text2[] = "Game Development in C";
	char* q = strstr(text2, "Develop");
	if(q != NULL)
	{
		printf("\"Develop\"를 찾은 위치부터: %s\n", q);
	}
	else
	{
		printf("\"Develop\"를 찾지 못했습니다.\n");
	}
	printf("\n");

	printf("=== 7. strtok ===\n");
	char langs[] = "C,C++,Java,Lua,Unreal";
	char* token = strtok(langs, ",");

	while(token != NULL)
	{
		printf("토큰: %s\n", token);
		token = strtok(NULL, ",");
	}

	return 0;
}
