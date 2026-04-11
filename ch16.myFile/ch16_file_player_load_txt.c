typedef struct Player
{
    char name[20];
    int level;
    int attack;
    int defense;
} Player;

int main(void)
{
    FILE* fp = fopen("player.txt", "r");
    if (!fp)
    {
        printf("파일 열기 실패\n");
        return 1;
    }

    char buffer[512];
    Player p;

    while (1)
    {
        char* ptr = fgets(buffer, sizeof(buffer), fp);
        if (!ptr)
            break;

        if (sscanf(buffer, "%19s %d %d %d",
                   , p.name, &p.level, &p.attack, &p.defense) == 4)
        {
            printf("이름:%s 레벨:%d 공격력:%d 방어력:%d\n",
                   p.name, p.level, p.attack, p.defense);
        }
    }

    fclose(fp);
    return 0;
}