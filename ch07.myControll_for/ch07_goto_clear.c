#include <stdio.h>
#include <stdlib.h>

int loadData(const char* filename)
{
	FILE* fp     =  NULL;	// 파일 리소스 초기화
	char* buffer =  NULL;	// 메모리 리소스 초기화
	int   result = -1;		// -1 실패: 0: 성공

	fp = fopen(filename, "r");	// 파일 열기
	if(fp == NULL)
		goto CLEAN_UP;		// 파일 열기 실패

	buffer = (char*)malloc(1024); // 메모리 할당
	if(buffer == NULL)
		goto CLEAN_UP;		// 메모리 할당 실패

	// 여기서 파일 읽기, 처리 등 여러 작업 수행
	// ...
	//

	result = 0;			// return 값 성공으로 변경
CLEAN_UP:
	// 자원 해제
	if(fp != NULL)
	{
		fclose(fp);
	}
	if(buffer != NULL)
	{
		free(buffer);
	}
	return result;			// 결과 반환
}


int main(void)
{
	int value=-1;

	do
	{
		printf("0 이상의 정수를 입력하세요: ");
		scanf("%d", &value);
	} while(value < 0);

	printf("입력한 값: %d\n", value);
	return 0;
}


