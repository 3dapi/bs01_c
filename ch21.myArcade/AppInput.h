#pragma once
#ifndef _AppInput_H_
#define _AppInput_H_

int InitInput(void);
int UpdateInput(void);
int DestroyInput(void);

// 키 이벤트 가져오기.
int GetKeyEvent(unsigned char keyCode);
// 입력 버퍼 가져오기.
const char* GetInputBuf(void);

#endif // _AppInput_H_
