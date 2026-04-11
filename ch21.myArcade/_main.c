
#include <stdio.h>
#include "AppMain.h"

int main(void)
{
    if(0>AppInit())
    {
        printf("AppInit failed.\n");
        return 1;
    }
    int hr = AppRun();
    return hr;
}
