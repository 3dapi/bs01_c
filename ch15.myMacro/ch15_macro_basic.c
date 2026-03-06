#include <stdio.h>

// 전처리 매크로 정의
#define SIZE 10
#define LOG_INFO(msg) printf("[INFO] %s\n", (msg))

int main(void)
{
    // 배열 선언 (전처리 치환 확인)
    int arr[SIZE] = {1, 2, 3, 4, 5};

    // 매크로 사용 (로그 출력)
    LOG_INFO("start");

    // 배열 출력
    for(int i = 0; i < SIZE; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    LOG_INFO("processing");

    // 간단한 연산 (합계)
    int sum = 0;
    for(int i = 0; i < SIZE; i++)
    {
        sum += arr[i];
    }

    printf("sum = %d\n", sum);

    LOG_INFO("end");

    return 0;
}
