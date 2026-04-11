#include <stdio.h>

int main(void)
{
    char data[] = "10 20";
    int x, y;

    if (sscanf(data, "%d %d", &x, &y) == 2)
    {
        printf("x=%d y=%d\n", x, y);
    }
    else
    {
        printf("파싱 실패\n");
    }

    return 0;
}
