#include <stdio.h>

int myStrCmp(const char s1[], const char s2[]);

int main(void)
{
	char str1[] = "Hello world";
	char str2[] = "Hello";

    int cmpValue = myStrCmp(str1, str2);

    printf("string compare: %d\n", cmpValue);

    return 0;
}

int myStrCmp(const char s1[], const char s2[])
{
    int i = 0;
    for(;s1[i] != '\0' && s2[i] != '\0'; ++i)
    {
        if (s1[i] != s2[i])
        {
            if(s1[i] > s2[i])
                return +1;
            else
                return -1;
         }
    }
    if(s1[i] == s2[i])
        return 0;
    else if(s1[i] > s2[i])
        return +1;
    return -1;
}

int myStrCmp2(const char s1[], const char s2[])
{
    int i = 0;

    // 두 문자가 같고, s1이 끝나지 않은 동안 계속 전진
    // (s1이 안 끝났는데 s2와 같다면, s2도 아직 안 끝난 상태)
    for(;s1[i] != '\0' && s1[i] == s2[i]; ++i)
    {
    }
    // 루프가 멈춘 지점(처음으로 달라진 곳)의 차이를 반환
    // 결과가 0이면 같음, 양수면 s1이 큼, 음수면 s2가 큼.
    return (unsigned char)s1[i] - (unsigned char)s2[i];
}