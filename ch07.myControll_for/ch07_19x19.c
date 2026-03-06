#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    printf("================= 19x19단 =================\n");
    for(int i=2; i<=19; i +=3)
    {
        printf("%2d단,          %2d 단,         %2d단\n", i+0, i+1, i+2);
        for(int j=2; j<19; ++j)
        {
            printf("%2d x %2d = %3d, %2d x %2d = %3d, %2d x %2d = %3d\n"
                    , i+0, j, (i+0)*j
                    , i+1, j, (i+1)*j
                    , i+2, j, (i+2)*j);
        }
        printf("\n");
    }

    printf("확인할 구구단을 입력하세요. 2~19단까지만 가능합니다.\n");
    do
    {
        int dan = 1;
        printf("\n확인할 구구단을 입력하세요.\n");
        if(0 == scanf("%d", &dan))
        {
            printf("프로그램 종료\n");
            break;
        }

        if(2>dan || dan>19)
        {
            printf("2~19단까지만 가능합니다.\n");
            continue;
        }

        for(int multi=2; multi <= 19; ++multi)
        {
            printf("%2d x %2d = %3d\n", dan, multi, dan*multi);
        }
    } while (1);
    
    return 0;
}
