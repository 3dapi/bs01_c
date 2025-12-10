#include <stdio.h>

int main(void)
{
    char name[20];
    int value;

    // 1. 위험한 입력 (길이 제한 없음)
    // scanf("%s", name);  // 위험

    // 2. 안전한 문자열 입력
    if (scanf("%19s", name) != 1)
    {
        printf("문자열 입력 오류\n");
        return 1;
    }

    printf("이름: %s\n", name);

    // 3. 정수 입력 + 반환값 검증
    if (scanf("%d", &value) != 1)
    {
        printf("정수 입력 오류\n");
        return 1;
    }

    printf("입력된 값: %d\n", value);

    return 0;
}
