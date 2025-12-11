#include <stdio.h>

void swap(int* a, int* b)
{
	int temp = *a;	// 임시 변수에 *a 값을 저장한다.
	*a = *b;		// b가 가르키는 주소의 값을 a 주소가 가르키는 주소에 저장한다.
	*b = temp;		// temp 값을 b 주소가 가르키는 주소에 저장한다.
}

void swap_ptr_int(int** a, int** b)
{
	int* temp = *a;	// a가 가리키는 포인터(즉, 원본 포인터)의 값을 temp에 보관한다.
	*a = *b;		// a가 가리키는 실제 포인터 값을 b가 가리키는 포인터 값으로 변경한다.
	*b = temp;		// b가 가리키는 포인터 값을 temp(원래 a가 가리켰던 포인터)로 변경한다.
}

void swap_ptr_generic(void** a, void** b)
{
	void* temp = *a;
	*a = *b;
	*b = temp;
}

int main(void)
{
	int a = 100, b= 200;
	swap(&a, &b);

	int* ptr_a = &a;
	int* ptr_b = &b;
	swap_ptr_int(&ptr_a, &ptr_b);

	return 0;
}

