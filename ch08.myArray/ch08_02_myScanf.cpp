#include <iostream>
#include <string>
#include <stdio.h>

std::string myScanf(void);

int main(void)
{
    printf("문자열을 입력하세요:");
    auto str = myScanf();
    printf("입력한 문자열: %s\n", str.c_str());

    return 0;
}

std::string myScanf(void)
{
	std::string str;
	// 개행 문자('\n')를 만날 때까지 입력 스트림의 모든 내용을 읽어 str에 저장
	std::getline(std::cin, str);
    return str;
}
