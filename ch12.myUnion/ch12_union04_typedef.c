#include <stdio.h>

//union Data {
//    int   i;
//    float f;
//    char  c;
//};
//
//// typedef 별칭 정의
//typedef union Data Data;
//typedef union Data* PtrData;
//
////사용 예:
//Data d;        // union Data d; 와 동일
//PtrData p = &d;

//typedef union {
//    int   i;
//    float f;
//    char  c;
//} Data, *PtrData;
//
//// 사용 예:
//Data d;         // union { ... } d; 와 동일
//PtrData p = &d; // 공용체 포인터

typedef union Data {
    int   i;
    float f;
    char  c;
} Data, *PtrData;

// 사용 예:
Data d;      // union Data d; 대신 Data를 직접 사용

int main(void)
{
    return 0;
}
