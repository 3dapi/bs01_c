#include <stdio.h>

int main(void)
{
    // 기본형 sizeof
    printf("sizeof(char)      =>  %zu\n", sizeof(char)        );
    printf("sizeof(short)     =>  %zu\n", sizeof(short)       );
    printf("sizeof(int)       =>  %zu\n", sizeof(int)         );
    printf("sizeof(long)      =>  %zu\n", sizeof(long)        );
    printf("sizeof(long long) =>  %zu\n", sizeof(long long)   );
    printf("sizeof(float)     =>  %zu\n", sizeof(float)       );
    printf("sizeof(double)    =>  %zu\n", sizeof(double)      );

    printf("---------------------------------------\n");

    // 문자 리터럴은 C에서 int 타입 ('A' => 65)
    printf("sizeof('A')       =>  %zu\n", sizeof 'A'     );
    // 문자열 리터럴은 null 문자 포함
    printf("sizeof(\"Hello\")   =>  %zu\n", sizeof "Hello" );
    // 정수 승격
    printf("sizeof(1+2)       =>  %zu\n", sizeof(1 + 2)  );
    // 실수 연산 => double 결과
    printf("sizeof(3 + 2.5)   =>  %zu\n", sizeof(3 + 2.5));

    printf("---------------------------------------\n");

    int a   = 10;
    short b = 10;
    short c = 10;
    double d = 3.14;
    int arr[20]={0};
    char* p = (char*)arr;     // 배열 arr의 주소를 char* 포인터로 저장

    printf("sizeof a          => %zu\n", sizeof a);        // 변수 a의 크기
    printf("sizeof(d)         => %zu\n", sizeof(d));       // double 변수 크기
    printf("sizeof(b + c)     => %zu\n", sizeof(b + c));   // short 연산은 int로 승격
    printf("sizeof(a + 1)     => %zu\n", sizeof(a + 1));   // 표현식의 결과 자료형 크기
    printf("sizeof(a == b)    => %zu\n", sizeof(a == b));  // 관계 연산 결과는 int
    printf("sizeof(arr)       => %zu\n", sizeof(arr));     // 배열 전체 크기
    printf("sizeof(arr[0])    => %zu\n", sizeof(arr[0]));  // 배열 요소 1개의 크기
    printf("sizeof(p)         => %zu\n", sizeof(p));       // 포인터의 크기
    printf("sizeof(*p)        => %zu\n", sizeof(*p));      // p가 가리키는 자료형의 크기
    printf("array elements    => %zu\n", sizeof(arr) / sizeof(arr[0])); // 배열 길이

    return 0;
}
