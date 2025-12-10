#include <stdio.h>

int main(void)
{
	int arr[32] = {0};

	int n=0;
	char name[100]={0,};
	int ret = scanf("%s, %d", name, &n);
	printf("scanf 결과: %d, 읽은 값: %s\n", ret, name);

	return 0;
}
