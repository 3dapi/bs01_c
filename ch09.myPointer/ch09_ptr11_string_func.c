#include <stdio.h>

void swap_ptr(void** a, void** b)
{
    void* temp = *a;
    *a = *b;
    *b = temp;
}

int myStrLen(const char* str)
{
	int len = 0;
	if(!str)
		return len; // str이 NULL인 경우 길이는 0으로 반환.

	// 널문자 전까지가 문자열의 길이.
	for(; *str; ++str, ++len)
	{
	}

	//while(*str)
	//{
	//	++str;
	//	++len;
	//}

	return len;
}


int myStrCpy(char* dst, const char* src)
{
	int len = 0;
	if(!src || !dst)
		return len; // str이 NULL인 경우 길이는 0으로 반환.

	// src의 문자를 dst로 복사하고, src가 널문자('\0')가 될 때까지 반복.
	for(;*dst++ = *src++; ++len)
	{
	}

	//while((*dst++ = *src++))
	//{
	//	len++;
	//}

	return len;
}

int myStrCmp(const char* s1, const char* s2)
{
	// 두 문자가 같고, s1이 끝나지 않은 동안 계속 전진
	// (s1이 안 끝났는데 s2와 같다면, s2도 아직 안 끝난 상태)
	for(;*s1 && (*s1 == *s2);++s1, ++s2)
	{
	}

	//while(*s1 && (*s1 == *s2))
	//{
	//	++s1;
	//	++s2;
	//}

	// 루프가 멈춘 지점(처음으로 달라진 곳)의 차이를 반환
	// 결과가 0이면 같음, 양수면 s1이 큼, 음수면 s2가 큼.
	return (unsigned char)*s1 - (unsigned char)*s2;
}


int main(void)
{
	char strSource[] = "Hello world, welcome!!!"; // source string
	char strDest[120] = {0};          // copied string

	int len = myStrCpy(strDest, strSource);
	int len2 = myStrLen(strDest);
	printf("string length: %d\n", len2);

	printf("string copy: %d - %s\n", len, strDest);


    return 0;
}

