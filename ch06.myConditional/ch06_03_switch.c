#include <stdio.h>

enum Command
{
	CMD_UNKNOWN  = -1,
	CMD_MOVE	 =  1,
	CMD_ATTACK	 ,
	CMD_QUIT	 ,
};

enum Command GetCommand(char key);

int main(void)
{
	char input = 0;

	printf("명령 입력 (G/A/Q): ");
	scanf(" %c", &input);

	enum Command cmd = GetCommand(input);

	switch(cmd)
	{
		case CMD_MOVE:
			printf("이동 명령\n");
			break;

		case CMD_ATTACK:
			printf("공격 명령\n");
			break;

		case CMD_QUIT:
			printf("종료 명령\n");
			break;

		default:
			printf("알 수 없는 명령입니다.\n");
			break;
	}

	return 0;
}

enum Command GetCommand(char key)
{
	switch(key)
	{
		case 'g':
		case 'G':
			return CMD_MOVE;
		case 'a':
		case 'A':
			return CMD_ATTACK;
		case 'q':
		case 'Q':
			return CMD_QUIT;
		default:
			return CMD_UNKNOWN;
	}
}
