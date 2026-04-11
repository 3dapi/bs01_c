#include <stdio.h>

void PrintMacroValue(void);

int main(void)
{
    PrintMacroValue();
    return 0;
}

void PrintMacroValue(void)
{
    printf("__FILE__: %s\n", __FILE__);
    printf("__LINE__: %d\n", __LINE__);
    printf("__DATE__: %s\n", __DATE__);
    printf("__TIME__ : %s\n", __TIME__);
    //printf("__STDC__ : %d\n", __STDC__);
    printf("__STDC_VERSION__ : %d\n", __STDC_VERSION__);
    printf("__func__: %s\n", __func__);
    printf("__FUNCTION__: %s\n", __FUNCTION__);
}
