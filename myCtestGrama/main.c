

//typedef struct tagCharacter {
//	char name[50];
//	int age;
//} Character;

struct Character {
	char name[50];
	int age;
} ;

// 여러번 선언에도 문제없다.
typedef struct Character Character;
typedef struct Character Character;
typedef struct Character Character;


// K&R 스타일(K&R C) 또는 Old-style C
// 1단계: 함수 이름 뒤 괄호 () 안에 매개변수 이름만 나열.
int add(a, b);

int main()
{
	Character a;
	Character b;

	a.age = 25;
	b.age = 30;

	return 0;
}

// 함수구현:
// 2단계: 괄호와 여는 중괄호 { 사이에서 각 매개변수의 타입을 선언
int add(a, b)
int a, b;	// 여기서 타입을 정의
{
	return a + b;
}
