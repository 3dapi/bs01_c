#include <stdio.h>

int main(void)
{
    printf("sizeof(char)        %zu\n", sizeof(char)        );
    printf("sizeof(short)       %zu\n", sizeof(short)       );
    printf("sizeof(int)         %zu\n", sizeof(int)         );
    printf("sizeof(long)        %zu\n", sizeof(long)        );
    printf("sizeof(long long)   %zu\n", sizeof(long long)   );
    printf("sizeof(float)       %zu\n", sizeof(float)       );
    printf("sizeof(double)      %zu\n", sizeof(double)      );
    printf("sizeof('A')         %zu\n", sizeof 'A'          );
    printf("sizeof(3 + 2.5)     %zu\n", sizeof(3 + 2.5)     );

    return 0;
}
