#include <stdio.h>

typedef void (*Callback)(void*);

void InvokeThreeTimes(Callback cb, void* userData)
{
    for (int i = 0; i < 3; ++i)
        cb(userData);   // 매번 같은 userData 전달
}

void PrintMessage(void* userData)
{
    const char* msg = (const char*)userData;
    printf("%s\n", msg);
}

int main(void)
{
    const char* text = "안녕하세요, 콜백입니다.";
    InvokeThreeTimes(PrintMessage, (void*)text);
    return 0;
}