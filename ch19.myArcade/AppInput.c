#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AppInput.h"

typedef struct Input
{
    char* buf;
    unsigned char* key;
}  Input;

static Input g_input;
static int bufSize = 512;   // 입력 버퍼 크기.
static int keySize = 256;   // 키 이벤트 배열 크기.

static void ResetInput(void);

// 키 이벤트 가져오기.
int GetKeyEvent(unsigned char keyCode)
{
    return g_input.key[keyCode];
}
// 입력 버퍼 가져오기.
const char* GetInputBuf(void)
{
    return g_input.buf;
}

// 입력 시스템 초기화.
int InitInput(void)
{
    g_input.buf = (char*)malloc(bufSize);
    if(!g_input.buf)
    {
        return -1;
    }
    g_input.key = (unsigned char*)malloc(keySize);
    if(!g_input.key)
    {
        free(g_input.buf);
        return -1;
    }
    ResetInput();
    return 0;
}

// 입력 시스템 업데이트.
int UpdateInput(void)
{
    // 매 프레임마다 입력 buffer, key 초기화.
    ResetInput();

    // fgets로 입력을 받음.
    fgets(g_input.buf, bufSize, stdin);
    // 문자열 끝의 '\n' 제거
    g_input.buf[strcspn(g_input.buf, "\n")] = '\0';
    // 첫 글자만 키 이벤트로 처리
    unsigned char ch = (unsigned char)g_input.buf[0];
    g_input.key[ch] = 1;

    return 0;
}

// 입력 시스템 해제.
int DestroyInput(void)
{
    printf("DestroyInput\n");
    if(g_input.buf)
    {
        free(g_input.buf);
        g_input.buf = NULL;
    }
    if(g_input.key)
    {
        free(g_input.key);
        g_input.key = NULL;
    }
    return 0;
}

// Input buffer 초기화
void ResetInput(void)
{
    memset(g_input.buf, 0, bufSize);
    memset(g_input.key, 0, keySize);
}
