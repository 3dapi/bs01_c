#include <stdio.h>
#include <stdint.h> // uintptr_t를 사용하기 위해 필요

int main()
{
	int value = 0x12345678;
	int* ptr = &value; // 포인터

	// 1. 포인터를 uintptr_t로 캐스팅
	uintptr_t address_as_int = (uintptr_t)ptr;

	// 2. 출력 (주소는 시스템마다 다르게 나옵니다)
	// %p는 포인터 주소를 출력하며, %lx는 부호 없는 long hexadecimal을 출력합니다.
	printf("Original Pointer Address: %p\n", (void*)ptr);
	printf("Address as uintptr_t (Hex): 0x%lx\n", (unsigned long)address_as_int);

	// (선택) 다시 포인터로 복원
	int* restored_ptr = (int*)address_as_int;
	printf("Restored Pointer Address: %p\n", (void*)restored_ptr);

	return 0;
}