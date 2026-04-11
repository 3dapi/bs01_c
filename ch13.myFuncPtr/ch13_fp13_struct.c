#include <stdio.h>

typedef struct Actor {
    float x, y;
    void (*update)(struct Actor* self, float dt);
    void (*draw)(struct Actor* self);
} Actor;


typedef void (*ButtonHandler)(void);

typedef struct Button {
    const char* text;
    ButtonHandler onClick;
} Button;

void StartGame(void)
{
    printf("게임을 시작합니다.\n");
}

void QuitGame(void)
{
    printf("게임을 종료합니다.\n");
}

void Click(Button* b)
{
    if (b->onClick)
        b->onClick();
}

int main(void)
{
    Button startButton = { "Start", StartGame };
    Button quitButton  = { "Quit",  QuitGame  };

    Click(&startButton);
    Click(&quitButton);
    return 0;
}
