#include <stdio.h>

enum ParamType {
    PARAM_INT,
    PARAM_FLOAT,
    PARAM_PTR
};

union ParamValue {
    int   i;
    float f;
    void* ptr;
};

struct Param {
    enum ParamType type;
    union ParamValue v;
};

void ProcessParam(struct Param p)
{
    switch (p.type)
    {
        case PARAM_INT:
            printf("정수 처리: %d\n", p.v.i);
            break;
        case PARAM_FLOAT:
            printf("실수 처리: %.2f\n", p.v.f);
            break;
        case PARAM_PTR:
            printf("포인터 처리: %p\n", p.v.ptr);
            break;
    }
}

int main(void)
{
    struct Param p;

    p.type = PARAM_INT;
    p.v.i = 100;
    ProcessParam(p);

    return 0;
}
