#include <stdio.h>

int main(void)
{
    int level = 5;
    double hp = 98.5;

    // printf
    printf("Level: %d, HP: %.1f\n", level, hp);

    FILE* fp = fopen("status.txt", "w");
    if (!fp)
        return 1;

    int gold = 100;

    // fprintf
    fprintf(fp, "Gold: %d\n", gold);
    fclose(fp);

    char buffer[128] = {0};
    int value = 123456789;

    // sprintf
    sprintf(buffer, "%d", value);

    printf("%s\n", buffer);
    return 0;
}
