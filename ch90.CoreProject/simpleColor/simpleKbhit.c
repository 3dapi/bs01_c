#include <stdio.h>
#include <conio.h>   // _kbhit, _getch 사용을 위한 헤더
#include <windows.h> // Sleep 사용을 위한 헤더

int main(void)
{
    int loopCount = 0;
    char key = '\0';

    printf("============== 키보드 입력 테스트 ==============\n");
    printf("명령: [W, A, S, D] 입력 시 방향 출력 / [Q] 종료\n");
    printf("\n");

    while (1)
    {
        if (_kbhit())                                       // 1. _kbhit() 키보드 입력 '체크'만.
        {
            key = _getch();                                 // 2. 입력이 확인된 경우에만 _getch()로 값을 읽음
            if (key == 'q' || key == 'Q')                   // 3. Q 누르면 종료
                break;

            system("cls"); // 화면 클리어 (Windows 전용)
            printf("\n[입력 확인] 누른 키: %c \n", key);
        }
        printf("\r");                                       // 4. 커서를 현재 줄의 맨 앞으로 이동
        printf("현재 루프 횟수: %d (입력 대기 중...)", ++loopCount);
        Sleep(100);                                         // 5. 0.1초마다 반복
    }
    printf("\n\n프로그램 종료\n");

    return 0;
}
