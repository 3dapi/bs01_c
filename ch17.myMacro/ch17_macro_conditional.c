#include <stdio.h>

// 플랫폼별 구현 선택
#if defined(_WIN32)
#include <windows.h>
static inline void sleep_ms(unsigned ms)
{
    Sleep(ms);
}
#elif defined(__APPLE__) && defined(__MACH__)
#include <TargetConditionals.h>
#include <unistd.h>
static inline void sleep_ms(unsigned ms)
{
    usleep(ms * 1000);
}
#elif defined(__ANDROID__) || defined(ANDROID)
#include <unistd.h>
static inline void sleep_ms(unsigned ms)
{
    usleep(ms * 1000);
}
#else
#error Unsupported platform
#endif

int main(void)
{
    printf("Start\n");

    for(int i = 0; i < 3; i++)
    {
        printf("Tick %d\n", i);
        sleep_ms(500);   // 플랫폼 독립 호출
    }

    printf("End\n");

    return 0;
}
