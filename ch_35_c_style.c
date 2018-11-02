/* C-Style������ �Լ� ���.
 *
 */


#include <stdio.h>


#define CASE	1

#if CASE

/* case 1: �Լ� ���
 �Լ��� �ڿ� ���� �Ѵ�.
 �̷� ����� ������ �θ���.

 ������ ���ַ��� �̸� �Լ��� �����ϰų� ������ ���־�� �Ѵ�.
 ���� Ÿ���� ���� ������ int�� �ȴ�.
 �����ּ��� ������ ������ �غ�����.
*/

/*
Func1();
int Func2();
int Func3();
*/


main()
{
	int a=10;
	float c=0;

	Func1();
	
	/* ������ �Լ��� ������ int�� �Ǿ� �־ �Ʒ��� �Լ��� ���ǿ���	*/
	/* float���� �Ǿ� �־											*/
	/* int�� ��ȯ�� �ȴ�.												*/
	c=Func2(a);
	printf("%f\n", c);


	Func3(&a);
}


Func1()
{
	printf("Func1 Call\n");
}


float Func2(k, l)
int k;
int l;
{
	printf("Func2 Call: arg1:%d arg2:%x\n", k, l);

	return 2.5f;
}


int Func3(k, l)
/* Call by Reference����*/
/* int& k;				*/	/* �̰��� �ȵȴ�.		*/
int* k;						/* ���� �� ��ĸ� �ȴ�.	*/
int* l;
{
	printf("Func3 Call: arg1:%d\n", *k);
}



#else


/* case 2: ����ü														*/
/* ����ü�� ����ϱ� ���ؼ� �ݵ�� �տ� struct Ű���带 �ٿ��� �Ѵ�.	*/
Func4();

struct MyStruct
{
	int a;
};



main()
{
	struct MyStruct st;
	st.a = 10;
	/* ������ �Լ��� ������ int�� �Ǿ� �־ �Ʒ��� �Լ��� ���ǿ���	*/
	/* float���� �Ǿ� �־											*/
	/* int�� ��ȯ�� �ȴ�.												*/
	Func4(&st);
}


Func4(pSt)
struct MyStruct	*pSt;
{
	printf("Func4 Call: MyStruct:%x, value: %d\n", pSt, pSt->a);
}

#endif
